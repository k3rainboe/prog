/*
Name: Ketan R. Yadav
Class: SE (B)
Roll No. 62

Problem Statement:
Write a Java program which will demonstrate a concept of Interfaces and packages: In this
assignment design and use of customized interfaces and packages for a specific application
are expected.

*/ 
 
import java.util.Scanner;
import test.A; 

interface sum{
	void add(int a);
}

class adder implements sum{
	public void add(int a){
		int res=a;
		while(a!=1)
		{
			res=res*(a-1);
			a--;
		}
		System.out.println("\nThe factorial is:" + res);
		A obj = new A();
		obj.rev(res);
	}
};

public class G27{  
	public static void main(String args[]){  
		System.out.println("\nThis Program demonstrates concept of Interface and Packages:");  
		adder obj = new adder();
		Scanner in = new Scanner(System.in);
		int n;
		System.out.println("\nEnter a number:");
		n = in.nextInt();
		obj.add(n);
	}
	  
} 

/*

Output:

gescoe@gescoe-OptiPlex-3010:~/Desktop/Ketan$ java G27

This Program demonstrates concept of Interface and Packages:

Enter a number:
7

The factorial is:5040

The Original Number was: 7

*/


