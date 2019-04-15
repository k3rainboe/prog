/*

Name: Ketan R. Yadav
Class: SE (B)
Roll No. 62

Problem Statement:
Write a program on template and exception handling in Java

*/


import java.io.*;

public class JavaExcept {

   public static void main(String args[]) {
      try {
         int a[] = new int[2];
         System.out.println("Access element three :" + a[3]);
      } catch (ArrayIndexOutOfBoundsException e) {
         System.out.println("Exception thrown  :" + e);
      }
      	finally{
      	System.out.println("Exception handlind");	
      	}
      System.out.println("Out of the block");
   }
}

/*
Output:

gescoe@gescoe-OptiPlex-3010:~/Desktop/Ketan$ java JavaExcept
Exception thrown  :java.lang.ArrayIndexOutOfBoundsException: 3
Out of the block


*/
