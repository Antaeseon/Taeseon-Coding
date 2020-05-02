package น้มุ;

import java.util.Scanner;

public class P2577 {

	public static void main(String[] args) {
		int [] arr = new int[10];
		int a,b,c,res;
		String s = "";
		Scanner sc = new Scanner(System.in);
		
		a= sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		res = a*b*c;
		s = Integer.toString(res);
		
		for(int i=0; i<s.length() ;i++) {
			arr[s.charAt(i)-'0']++;
		}
		
		for(int i=0;i<10;i++) {
			System.out.println(arr[i]);
		}
	}

}
