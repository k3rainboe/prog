   

/*
PROBLEM STATEMENT:-Assume we have two input and two output tapes to perform the sorting. The internal memory
can hold and sort m records at a time. Write a program in java for external sorting. Find out
time complexity.
*/
import java.util.Scanner;
class merge
{

  static int []a,b,c;
  static int n1,n2;

  static void accept()
  {
    Scanner scan=new Scanner(System.in);
    
    int temp;

    System.out.print("\nenter the size of first array : ");
    
    n1=scan.nextInt();
    
    System.out.print("\nenter the size of second array : ");
    n2=scan.nextInt();
    
    a=new int[n1];
    b=new int[n2];
         
    System.out.println("\nenter the element for first array : ");
      for(int i=0;i<n1;i++)
        a[i]=scan.nextInt();
                    
    System.out.println("\nenter the element for second array : ");
      for(int i=0;i<n2;i++)
        b[i]=scan.nextInt();
    
      for(int i=0;i<n1-1;i++)
      {
          for(int j=i+1;j<n1;j++) 
          {
              if(a[i]>a[j])
              {
                  temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
              }
          }
      }                         
     
      for(int i=0;i<n2-1;i++)
      {
          for(int j=i+1;j<n2;j++) 
          {
              if(b[i]>b[j])
              {
                  temp=b[i];
                  b[i]=b[j];
                  b[j]=temp;
              }
          }
      }      
  }
    
  static void sort()         //merge sort
  {
     c=new int[n1+n2];
     int i=0,j=0,k=0;
     
      while(i<n1 && j<n2)
      {
          if(a[i]==b[j])
          {
              c[k++]=a[i++];
              c[k++]=b[j++];
          }
     
          if(a[i]>b[j])
          {
              c[k++]=b[j++];
          }
          else if(a[i]<b[j])
          {
              c[k++]=a[i++];
          }
      }          
     
      while(i<n1)
      c[k++]=a[i++];
     
      while(j<n2)
      c[k++]=b[j++];
                 
      System.out.print("sorted array : ");
      for(int l=0;l<n1+n2;l++)
      System.out.print(c[l]+" ");
  
  }
        

  public static void main(String args[])
  {
      accept();
      sort();

  }                                                  

}                         
