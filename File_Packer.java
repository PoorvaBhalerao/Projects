//////////////////////////////////////////////////////////////////////////////
//                          FILE PACKER UNPACKER
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                          FILE PACKER
/////////////////////////////////////////////////////////////////////////////

import java.io.*;// for File class
import java.util.*;

class File_Packer
{
    public static void main(String Args[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("---------------File Packer Unpacker CUI Module--------------");

        System.out.println("------------------------------------------------");
        System.out.println("------------------Packing Activity--------------------");
        System.out.println("------------------------------------------------");

        System.out.println("Enter the name of directory that you want to open: ");
        String FolderName = sobj.nextLine();

        File fobj = new File(FolderName);

        System.out.println("Enter the name of Packed file that you want to create: ");
        String PackedFile = sobj.nextLine();

        File Packobj = new File(PackedFile);

        boolean bRet = Packobj.createNewFile();

        if(bRet == false)
        {
            System.out.println("Unable to create Packed File");
            return;
        }

        FileOutputStream foobj = new FileOutputStream(Packobj);

        if(fobj.exists())
        {
            int i = 0, j = 0;
            File Arr[] = fobj.listFiles();

           
            String Header = null;
            int iRet = 0;
            byte Buffer[] = new byte[1024];
            int iCount = 0;

            FileInputStream fiobj = new FileInputStream(Arr[i]);
            
            for(i = 0; i<Arr.length; i++)
            {
                Header = Arr[i].getName();
                if(Header.endsWith(".txt")) // only .txt files are going to packing 
                {
                    Header = Header + " " + Arr[i].length();

                    for(j = Header.length(); j<100; j++)
                    {
                        Header = Header + " ";
                    }
                    System.out.println("Header of file is: ");    
                    System.out.println(Header);

                    System.out.println("Length of Header is : "+ Header.length());

                    foobj.write(Header.getBytes(), 0 , 100);

                    fiobj = new FileInputStream(Arr[i]);

                    while((iRet = fiobj.read(Buffer)) != -1)
                    {
                        foobj.write(Buffer, 0, iRet);
                    }
                    fiobj.close();
                    iCount++;
                }                
            }

            System.out.println("Number of scaned are: "+Arr.length);
            System.out.println("Number of files packed: "+iCount);
            

            System.out.println("Thank you for using File Packer and Unpacker Tool");

        }
        else
        {
            System.out.println("There is no such Directory");
        }
    }
}