package น้มุ;

import java.util.Scanner;

public class P11720 {

	public static void main(String[] args) {
		int n;
		String res;
		int solu=0;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		res = sc.next();
		
		for(int i=0;i<res.length();i++) {
			solu+=(res.charAt(i)-'0');
		}
		System.out.println(solu);
	}

}
