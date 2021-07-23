#include<iostream>
#include<string> //string header to use the string variable(string is not native in c++)
#include<fstream>//fstream is needed because we will use file systems.
#include <stdlib.h> //Added for simple GUI effect
#include <sstream> 


using namespace std;
 

fstream storage; /*declaring fstream global variable used to open, write, read and close files in this program.*/
  
char select; //global var for multiple switch case

 
struct student_profile{
    char FName[100];
    char LName[100];
    char age[100];
    char brgy[100];\
    char Mty[100];
    char city[100];
	char reg_year[100];
    char TFname [100];
	char TLname [100];
	char Mname [100];
    char course[100];
    int id_No;
    int no_subject;
    char course_Name[100];
    char subject_Name[100];
    int credit_hour;
    int quiz_one;
    int quiz_two;
    int quiz_three;
    int mid;
    int assignment;
    int lab;
    int final_exam;
    int totalMark;
};  
 
/* creating structure variable from student_profile.
   the name this structure variable is student.
   it is used to hold name, last name, id etc
*/
student_profile student; 
 
 
/* function used to register student.
   it accept student details then it write those data to file.
   so student details will be saved in text file for later use.
*/
 
void stud_details(){
	cout<<"\n\n";
    cout<<"\n  ID: " <<student.id_No <<endl; 
	cout<<"  Name: "<<student.FName<<" "<<student.Mname<<" "<<student.LName<<endl;
	cout<<"  Course_YS: "<<student.course<<endl;
	cout<<"\n  Address: "<<student.brgy<<"  "<<student.Mty<<"  "<<student.city<<endl;
	cout<<"  Reg.Year: "<<student.reg_year<<endl;
	cout<<"  Teacher: "<<student.TFname<<" "<<student.TLname<<endl;
	cout<<"\n";
	cout<<"  *****************************************************************************\n";
	cout<<"  *                           STUDENT MARK LIST                               *\n";
	cout<<"  -----------------------------------------------------------------------------\n";   
	cout<<"  Subject        Quiz1   Quiz2   Quiz3    Mid   Asgmts    Final   Total   Grade\n";
	cout<<"  -----------------------------------------------------------------------------\n";
} 


void form(){
	
 cout<<"" <<endl;cout<<"" <<endl;cout<<"" <<endl;
 cout<<"	Please fill-up the form... \n\n";
 
 cout<<"        Student IDNumber: ";
 cin>>student.id_No;
 
 cout<<"\n        First Name: ";
 cin>>student.FName;
 cout<<"        Last Name: ";
 cin>>student.LName;
 cout<<"        Middle Name: ";
 cin>>student.Mname;
 cout<<"        Age:    ";
 cin>>student.age;
 // -------------------------------------------
 cout<<"\n        Brgy.: ";
 cin>>student.brgy;
  cout<<"        Municipality: ";
 cin>>student.Mty;
  cout<<"        City: ";
 cin>>student.city;

 cout<<"\n        Teachers FirstName:  ";
 cin>>student.TFname;
 cout<<"        Teachers LastName:  ";
 cin>>student.TLname;
// -------------------------------------------
 cout<<"\n        Course-Y_S: ";
 cin>>student.course;
 cout<<"        Registration year: ";
 cin>>student.reg_year;
 cout<<"        Number of Subject: ";
 cin>> student.no_subject;
  
  
/* for loop used to register multiple courses for one student
   based on the student's number of courses entered.
 */
 for(int a=1; a<=student.no_subject; a++) {
 cout<<"        Subject Name: ";
 cin>>student.subject_Name;
 cout<<"\n";
 cout<<"        QUIZES\n";
 cout<<"         First: ";
 cin>>student.quiz_one;
 cout<<"         Second: ";
 cin>>student.quiz_two;
 cout<<"         Third: ";
 cin>>student.quiz_three;
 cout<<"\n";
 cout<<"        EXAMS/ASGMTS/LABS\n";
 cout<<"         Midterm: ";
 cin>>student.mid;
 cout<<"         Assignment: ";
 cin>>student.assignment;
 cout<<"         Lab: ";
 cin>>student.lab;
 cout<<"         Finals: ";
 cin>>student.final_exam;
 storage.open("marklist.txt",ios::app) ;
   storage.write((char*)&student,sizeof(student));
   //storage.write(student,sizeof(student));
 storage.close();
 cout<<"\n\n";
            
  }
}


void function_to_register(){
 system("CLS");
 cout<<"" <<endl;
 cout<<"  \n   ****************  REGISTER NEW STUDENT  *****************               \n";
form();  //-------------------------------------------------------------------------------------
  system("CLS");// Clears screen after selected choice is entered
  cout<<"\n\n\n\n\n\n\n";
 
 cout<<"          STUDENT REGISTERED SUCCESSFULLY! \n\n\n";
 
 cout<<"           Do you want to Add more? y/n:";
 				   
 cin>>select;
  
  switch (select) 
  {
        case 'Y': case 'y':
     		function_to_register();
     		system("CLS");
     	    break;
           
		case 'N': case 'n':
     		//break statement will do for main menu return
            break; 
		default: 
		cout<<"\nInvalid choice.."; 
		getchar(); 
//		return;
		switch(select);
		
		
 }
 
}
  
 
 /* function used to calculate grade of each course. 
    we call this function when the program is displaying grade of student.
 */
void grade_calculator(int totalMark)
 { 
    if(totalMark>=90 && totalMark<=100)
        cout<<"A+";
    else if(totalMark>=80 && totalMark<90)
        cout<<"A";
    else if(totalMark>=70 && totalMark<80)
        cout<<"B";
    else if(totalMark>=60 && totalMark<70)
        cout<<"C+";
    else if(totalMark>=50 && totalMark<60)
        cout<<"D";
    else if(totalMark>=0 && totalMark<50)
        cout<<"F";
    else
        cout<<"NG";   
    }
     
     
/* function used to display registered students on the screen.
   this function gets the registered student from that file 
   we used above to store student details.
*/
void seeRegistered()
 {    
// storage.open("marklist.txt",ios::app);
// storage.close();
 
 cout<<"\n\n                           ******* STUDENTS RECORD ******* \n";
 storage.open("marklist.txt",ios::in);
 storage.read((char*)&student,sizeof(student));
 
 while (storage.eof()==0) { 
  cout<<"\n\n\n";
  
  stud_details();
                 
   
/* for loop used to print all courses and their marks
   for a single student.
*/
     for(int t=1; t<=student.no_subject; t++) 
	 {     
     	
     	student.totalMark= (student.quiz_one+student.quiz_two+student.quiz_three+student.assignment+student.mid+student.final_exam)/6; 
  		cout<<"  "<<student.subject_Name<<"     "<<student.quiz_one<<"      "<<student.quiz_two<<"       "<<student.quiz_three<<"        "<<student.mid<<"       "<<student.assignment<<"          "<<student.final_exam<<"      "<<student.totalMark<<"      "; 
     	grade_calculator(student.totalMark);
     	cout<<endl;
     	storage.read((char*)&student,sizeof(student)); 
     	
     } 
  }

storage.close();
getchar();
}
 
void searchStud()
{
 int id_input;
 cout<<"\n\n\n\n\n                                                ### Search a Student ###\n"; 
 cout<<"\n                                                   Enter Stundent ID: "; //seach student using id.
 cin>>id_input;	
 cout<<"" <<endl;
// storage.open("marklist.txt",ios::app);
// storage.close();
 
 storage.open("marklist.txt",ios::in);
 storage.read((char*)&student,sizeof(student));
 
 	while (storage.eof()==0) 
		{ 
//		 stringstream raw(student.id_No);
//		 int x=0;
//		 raw >> x;
			
	  	
		  	if(student.id_No == id_input) // comparing id number to the current searched id 
			{
//				for (int i = 0; i <= 1; i) {
//  				cout << i << "\n";
				stud_details();
	
					for(int t=1; t<=student.no_subject; t++) 
				{
								        
				student.totalMark= (student.quiz_one+student.quiz_two+student.quiz_three+student.assignment+student.mid+student.final_exam)/6; 
		  		cout<<"  "<<student.subject_Name<<"     "<<student.quiz_one<<"      "<<student.quiz_two<<"       "<<student.quiz_three<<"        "<<student.mid<<"       "<<student.assignment<<"          "<<student.final_exam<<"      "<<student.totalMark<<"      "; 
		     	grade_calculator(student.totalMark);
		     	cout<<endl;
		     	storage.read((char*)&student,sizeof(student));
		    	}
		      } 
		    storage.read((char*)&student,sizeof(student));
		    	 
		}
	storage.close();
	getchar();
}

void update_Rec(){
 
 system("CLS");
 storage.open("marklist.txt",ios::in);
 storage.read((char*)&student,sizeof(student));
 
 
 cout<<"" <<endl;
 cout<<"  \n   ****************  UPDATE RECORD  *****************               \n";
 form();  //-------------------------------------------------------------------------------------

  system("CLS");// Clears screen after selected choice is entered
  cout<<"\n\n\n\n\n\n\n";
 
 cout<<"              UPDATE SUCCESSFULLY! \n\n\n";
 
 cout<<"           Do you want to update more? y/n:";
 cin>>select;
   
  switch (select) 
  {
        case 'Y': case 'y':
     		function_to_register();
     		system("CLS");
     	    break;
           
		case 'N': case 'n':
     		//break statement will do for main menu return
            break; 
        
		default: 
			cout<<"\nInvalid choice.."; 
			getchar(); 
			switch(select);
 }
}

void delete_Rec() //this code was unfinished(this will basically only remove the data in the current textform database) 
{

  string line, name = "delete";
  ifstream storage;
  ofstream temp;
  storage.open("marklist.txtt");
  temp.open("temp.txt");
  while (getline(storage, line))
  {
    if (line != name)
      temp << line << endl;
  }
   system("CLS");
  cout << "\n\n\n\n       ### RECORDS DELETED SUCCESSFULLY! ###" << endl;
  storage.close();
  temp.close();
  remove("marklist.txt");
  rename("temp.txt", "marklist.txt");
  getchar();
}

 
/* This is the main function which will be  executed before all functions,
   So in this program when the user select one option then by 
   the help switch statement the user redirects to appropriate function.
 */
 int main()
  { 
 
 
/* while loop that help us to excute the program all time.
   this means the program will not exit without our interest.*/
 while(1) { 
  //cout<<endl; cout<<endl; cout<<endl;
  //cout<<endl;
  system("CLS");
  cout<<"     ********************************************************\n";
  cout<<"     *       STUDENT REGISTRATION AND MARK LIST SYSTEM      *\n";
  cout<<"     ********************************************************\n";
  cout<<"     *                                                      *\n";
  //cout<<"     ******************************************************\n";
  cout<<"      *  Enter 1: Register new student                     *\n";
  cout<<"      *  Enter 2: Show registerd student with grades       *\n";
  			  /*
  			  	you can improve this in which the displayed record is sorted (ascending/descending)
				*/	
  cout<<"      *  Enter 3: Search a student                         *\n";
  cout<<"      *  Enter 4: Edit student record                      *\n";
  cout<<"      *  Enter 5: Delete student record                    *\n";  
  
  cout<<"      *  Enter 0: Exit                                     *\n";
  cout<<"     *                                                      *\n";
  cout<<"     ********************************************************\n";
  cout<<"     Selected:"; 
  system("Color 0D"); 
  cin>>select;
  
  system("CLS");// Clears screen after selected choice is entered

 
  switch (select) 
  {
        case '1':
     		function_to_register();
     	    break;
   		
		case '2':
     		seeRegistered();
            getchar();
			break;
        
        case '3':
        	searchStud();  
			
			getchar();  	
            break;
            
        case '4':
     		delete_Rec();
     		cout << " \n\n ###  All record will be deleted before an update ###\n\n"; 
			cout << " \n\n\n\n\n              Press any key to continue: ";
     		getchar();
     		update_Rec();
			getchar();
			break;
			
        case '5':
     		cout << "  ###  THIS WILL DELETE ALL THE RECORDS ###\n\n";
     		cout << " \n\n        Do you want to continue Y/N: ";
     		cin>>select;
			
			switch(select){
				 	
			case 'Y': case 'y':
	     		delete_Rec();
	     		getchar();
	     		break;
           
			case 'N': case 'n':
	     		//break statement will do for main menu return
	            break; 
     			}
            main();
                
		case '0':
			return 0;
			break;
			
			char chaka;
			default: 
			cout<<"\n\n\n\n\n\n                                                  XxX INVALID CHOICE XxX";
			cout<<"\n\n                                                    Press R to return:"; //improvised for shorter time excecution(Any keys will do)
			cin>>chaka;
			main();
			getchar();       
			
  }
 }
 
}



