import java.util.Scanner;
class Employee{
	
	private long id;
	private String name;
	private int age;
	private double salary;
	
	public Employee(){
	
	}
	
	public void insert(){
		
		Scanner s = new Scanner(System.in);
		System.out.println("Enter name -> ");
		this.name = s.nextLine();
		System.out.println("Enter id -> ");
		this.id = s.nextInt();
		System.out.println("Enter age -> ");
		this.age = s.nextInt();
		System.out.println("Enter salary -> ");
		this.salary = s.nextDouble();
	}
	public void showDetails(){
		
		System.out.println("Name -> " + name);
		System.out.println("Id -> " + id);
		System.out.println("Age -> " + age);
		System.out.println("Salary -> " + salary);
	}
	public String getName(){
		
		return name;
	}
	
}
public class EmployeeDatabase{
	
	public static void main(String args[]){
		
		Employee emp[] = new Employee[50];
		int no = 1;
		int choice = 0;
		String name = " ";
		
		while(true){
			
			Scanner p = new Scanner(System.in);
			System.out.println("1. Add new employee");
			System.out.println("2. Display details of a employee");
			choice = p.nextInt();
			
			switch(choice){
			
				case 1: emp[no] = new Employee();
						emp[no].insert();
						no += 1;
						break;
						
				case 2: System.out.println("Enter employee name -> ");
						p.nextLine();
						p.close();
							for(int i=1; i<no; i++){
						
								if( name == emp[i].getName()){
									
									emp[i].showDetails();
									break;
								}
							}
							System.out.println(name + "not found in database");
		
			}
			
		}
		
	}
}
