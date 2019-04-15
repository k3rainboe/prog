/*

Name: Ketan R. Yadav
Class: SE (B)
Roll No. 62

Problem Statement:
Write a Java program which will demonstrate a concept of Interfaces and packages: In this
assignment design and use of customized interfaces and packages for a specific application
are expected.

*/
package test;  
public class A{  
	public void rev(int res){
	int n=1;
	while(res!=1)
		{
			res=res/n;
			n++;
		}
		n--;
 	System.out.println("\nThe Original Number was: " + n);
 	}  
}  

