package น้มุ;

import java.util.Scanner;

public class p10818 {

	public static void main(String[] args) {
		int min,max;
		max = -10^9;
		min = 10^9;
		
		int n;
		int input;
		Scanner sc = new Scanner(System.in);
		n= sc.nextInt();
		
		for(int i=0;i<n;i++) {
			input = sc.nextInt();
			
			if(input>max)
				max=input;
			if(input<min)
				min=input;
		}
		System.out.print(min +" "+max);
	}

}
