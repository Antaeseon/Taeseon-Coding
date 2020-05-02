package น้มุ;

import java.util.Scanner;

public class P1152 {

	public static void main(String[] args) {
		int n=0;
		boolean check = false;
		String inp;
		Scanner sc = new Scanner(System.in);
		
		inp=sc.nextLine();
		
		for(int i=0;i<inp.length();i++) {
			if(!check) {
				if(inp.charAt(i)!=' ') {
					n++;
					check=true;
				}
			}else {
				if(inp.charAt(i)==' ') {
					check=false;
				}
			}
		}
		
		System.out.println(n);
	}

}
