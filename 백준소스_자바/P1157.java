package น้มุ;

import java.util.Scanner;

public class P1157 {

	public static void main(String[] args) {
		int [] res = new int[26];
		int index=-1;
		String inp;
		Scanner sc = new Scanner(System.in);
		int maximum=0;
		inp =sc.nextLine();
		
		inp = inp.toUpperCase();
		for(int i=0;i<inp.length();i++) {
			res[inp.charAt(i)-'A']++;
		}
		
		for(int i=0;i<26;i++) {
			if(res[i]>maximum) {
				index=i;
				maximum=res[i];
			}else if (res[i]==maximum){
				System.out.println("?");
			}
		}
		System.out.println((char)('A'+index));
	}

}
