// Study Tracker

import java.util.*;

import javax.swing.text.View;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.io.*;

//done
class StudyLog
{
    private LocalDate Date;
    private String Subject;
    private double Duration;
    private String Description;

    public StudyLog(LocalDate a,String b, double c, String d)
    {
        this.Date = a;
        this.Subject = b;
        this.Duration = c;
        this.Description = d;
    }

    public LocalDate getDate()
    {
        return this.Date;
    }

    public String getSubject()
    {
        return this.Subject;
    }

    public double getDuration()
    {
        return this.Duration;
    }

    public String getDescription()
    {
        return this.Description;
    }

    @Override
    public String toString()
    {
        return Date+"   |   "+Subject+"   |   "+Duration+"   |   "+Description;
    }
}

//done
class StudyTracker
{
    public ArrayList<StudyLog> Database = new ArrayList<StudyLog>();

    public void InsertLog()
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("-----------------------------------------------------------");
        
        System.out.println("-----------Enter valid details of your study---------------");
        
        System.out.println("-----------------------------------------------------------");

        LocalDate Dateobj = LocalDate.now();

        System.out.println("Please enter the name of Subject like C/C++/Java/Python: ");
        String sub = sobj.nextLine();

        System.out.println("Please entter the time period of your study in hours: ");
        double dur = sobj.nextDouble();
        sobj.nextLine();

        System.out.println("Please provide Description of your study:");
        String desc = sobj.nextLine();

        StudyLog studyobj = new StudyLog(Dateobj, sub, dur, desc);

        Database.add(studyobj);

        System.out.println("Study Log gets stored Successfully");

        System.out.println("-----------------------------------------------------------");
        
    }

    public void DisplayLog()
    {
        System.out.println("-----------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("----------------Nothing to Display-------------------------");
            System.out.println("-----------------------------------------------------------");

            return;
        }

        System.out.println("------------------Log Report of Study Tracker--------------");

        System.out.println("-----------------------------------------------------------");

        for(StudyLog s : Database)
        {
            System.out.println(s);                  // it will call to toString method

        }
        System.out.println("-----------------------------------------------------------");
    }

    public void ExportCSV()
    {
        System.out.println("-----------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("-------------------Nothing to Export-----------------------");
            System.out.println("-----------------------------------------------------------");

            return;
        }

        String FileName = "StudyTracker.csv";

        try(FileWriter fwobj = new FileWriter(FileName))
        {
            fwobj.write("Date, Subject, Duration, Description\n");
            
            for(StudyLog s: Database)
            {
                fwobj.write(s.getDate()+","+
                            s.getSubject().replace(","," ")+","+                // if user enters 2-3 projets seperated by comma
                            s.getDuration()+","+
                            s.getDescription().replace(","," ")+"\n");
            }

            System.out.println("Database gets exported in csv: "+FileName);
        }
        catch(Exception eobj)
        {
            System.out.println("Exception occured in csv handling");
        }
    }

    public void SummaryByDate()
    {
        System.out.println("-----------------------------------------------------------");
        if(Database.isEmpty())
        {
            System.out.println("Nothing to Display as Data is empty");
            System.out.println("-----------------------------------------------------------");

            return;
        }

        System.out.println("---------Summary by Date from Study Tracker-------------");
        System.out.println("-----------------------------------------------------------");

        TreeMap<LocalDate, Double> tobj = new TreeMap<LocalDate, Double>();

        LocalDate lobj = null;
        double d = 0.0, old = 0.0;
        
        for(StudyLog sobj : Database)
        {
            lobj = sobj.getDate();
            d = sobj.getDuration();

            if(tobj.containsKey(lobj))
            {
                old = tobj.get(lobj);
                tobj.put(lobj, d+old);
            }
            else
            {
                tobj.put(lobj,d);
            }
        }

        //Display the details as per Date
        for(LocalDate l: tobj.keySet())
        {
            System.out.println("Date: "+l+" Total Study Duration: "+tobj.get(l));
        }

        System.out.println("-----------------------------------------------------------");          

    }



    public void SummaryBySubject()
    {
        System.out.println("-----------------------------------------------------------");
        if(Database.isEmpty())
        {
            System.out.println("Nothing to Display as Data is empty");
            System.out.println("-----------------------------------------------------------");

            return;
        }

        System.out.println("---------Summary by Subject from Study Tracker-------------");
        System.out.println("-----------------------------------------------------------");

        TreeMap<String, Double> tobj = new TreeMap<String, Double>();

        String s = null;
        double d = 0.0, old = 0.0;
        
        for(StudyLog sobj : Database)
        {
            s = sobj.getSubject();
            d = sobj.getDuration();

            if(tobj.containsKey(s))
            {
                old = tobj.get(s);
                tobj.put(s, d+old);
            }
            else
            {
                tobj.put(s,d);
            }
        }

        //Display the details as per subject
        for(String str: tobj.keySet())
        {
            System.out.println("Subject: "+str+" Total Study Duration: "+tobj.get(str));
        }

        System.out.println("-----------------------------------------------------------");        
    }

}


class Study_Tracker
{
    public static void main(String[] args)
    {
        Scanner sobj = new Scanner(System.in);

        StudyTracker stobj = new StudyTracker();

        int iChoice = 0;

        System.out.println("-----------------------------------------------------------");

        System.out.println("-------------Welcome To Study Traker-----------------------");
        System.out.println("-----------------------------------------------------------");

        do
        {
            System.out.println("Please select appropriate option: ");
            System.out.println("1: Insert new Study Log");
            System.out.println("2: View all Study Logs");
            System.out.println("3: Export Study Log to csv");
            System.out.println("4: Summary of Study Log by date");
            System.out.println("5: Summary of Study Log by Subject");
            System.out.println("6: Exit the application");

            iChoice = sobj.nextInt();

            switch (iChoice) {
                case 1:
                    stobj.InsertLog();          //Insert new Study Log            
                    break;

                case 2:
                    stobj.DisplayLog();         //View all Study Logs             
                    break;

                case 3:
                    stobj.ExportCSV();          //Export Study Log to csv             
                    break;

                case 4:
                    stobj.SummaryByDate();      //Summary of Study Log by date                
                    break;

                case 5:
                    stobj.SummaryBySubject();   //Sumamry of study log by Subject                   
                    break;

                case 6:                         //Exit the Application
                    System.out.println("-----------------------------------------------------------");
                    System.out.println("------------Thank you for using Study Tracker--------------");
                    System.out.println("-----------------------------------------------------------");
                    break;
            
                default:
                    System.out.println("Please enter valid option");
                    break;
            }



        }while(iChoice != 6);   // end of do-while

    }   // end of main
}   // end of starter class

/*
    main->
    StudyTracker->
    StudyLog


*/