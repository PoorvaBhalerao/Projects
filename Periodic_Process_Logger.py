# Write Automation script which accepts time interval from user and 
# create log file in that. Marvellous directory which contains information of all running processes
# After creating log file send log file through mail

import os 
import time
import psutil # type: ignore
import urllib.request # type: ignore
import smtplib
import schedule # type: ignore
from sys import *
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

def is_connected():
    try:
        urllib.request.urlopen("http://www.google.com", timeout = 1)
        return True
    except urllib.request.URLError as err:
        return False
    
def MailSender(filename, time):
    try:
        fromaddr = "practiceccppjavapython@gmail.com"
        toaddr = "patankarpp1995@gmail.com"

        msg = MIMEMultipart()

        msg['From'] = fromaddr

        msg['To'] = toaddr

        body = """
        Hello %s
        Welcome,
        Please find attatched document which contains Log of Running Processes
        Log File is created ar : %s

        This is auto generated mail.

        Thanks and Regards,
        Poorva Bhalerao
        """ % (toaddr,time)

        Subject = """
        Process Log generated at: %s
        """%(time)

        msg['Subject'] = Subject

        msg.attach(MIMEText(body, 'plain'))

        attachment = open(filename, 'rb')

        p = MIMEBase('application', 'octet-stream')

        p.set_payload((attachment).read())

        encoders.encode_base64(p)

        p.add_header('Content-Disposition',"attatchment; filename = %s" % filename)

        msg.attach(p)

        s = smtplib.SMTP('smtp.gmail.com',587)

        s.starttls()

        s.login(fromaddr, "jpvg nolz rlzv pnvc")

        text = msg.as_string()

        s.sendmail(fromaddr, toaddr, text)

        s.quit()

        print("Log file is successfully sent through mail")

    except Exception as E:
        print("Unable to send main.",E)


def ProcessLog(log_dir = "Marvellous"):
    listprocess = []

    if not os.path.exists(log_dir):
        try:
            os.mkdir(log_dir)
        except:
            pass
    
    timestamp = time.ctime()
    timestamp = timestamp.replace(" ", "")
    timestamp = timestamp.replace(":","_")
    timestamp = timestamp.replace("/","_")
    
    seperator = "-"*80
    log_path = os.path.join(log_dir, "Marvellous%s.log" %(timestamp))
    # log_file_path = os.path.join("Marvellous", "process_log.txt")
    os.makedirs(os.path.dirname(log_path), exist_ok=True)
    f = open(log_path, "w")
    f.write(seperator + "\n")
    f.write("Marvellous Infosystems Process Logger: "+time.ctime()+ "\n")
    f.write(seperator + "\n")
    f.write("\n")

    for proc in psutil.process_iter():
        try:
            pinfo = proc.as_dict(attrs = ['pid','name','username'])
            vms = proc.memory_info().vms/(1024 *1024)
            pinfo['vms'] = vms
            listprocess.append(pinfo)
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass

    for element in listprocess:
        f.write("%s\n" % element)

    print("Log file is successfully generated at location %s" %(log_path))

    connected = is_connected()

    if connected:
        starttime = time.time()
        MailSender(log_path, time.ctime())
        endtime = time.time()

        print(f"Took {endtime - starttime:.2f} seconds to send mail")

    else:
        print("There is no internet connection")


def main():
    print("Application name: "+argv[0])

    if(len(argv) != 2):
        print("Error: Invalid number of arguments type 'h' for help and 'u' for usage")
        exit()

    if(argv[1] == 'h') or (argv[1] == 'H'):
        print("this script is used to log record of running processes")
        exit()

    if(argv[1] == 'u') or (argv[1] == 'U'):
        print("Usage: ApplicationName time_interval")
        exit()

    try:
        interval = int(argv[1])
        if interval <= 0:
            raise ValueError("The time interval must be positive inteeger.")
        
        schedule.every(interval).minutes.do(ProcessLog)
    
        while True:
            schedule.run_pending()
            time.sleep(1)

    except ValueError as e:
        print(f"Error: {e}")

    except Exception as E:
        print("Error: Invalid input",E)
    


if __name__ == "__main__":
    main()

    







