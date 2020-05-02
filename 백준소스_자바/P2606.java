package น้มุ;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class eleme{
	int x;
	int y;
}


public class P2606 {
	public static void main(String[] args) {
		int[][]map = new int[101][101];
		boolean []visited = new boolean[101];
		int n;
		int m;
		int x,y;
		int res=1;
		Scanner sc = new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		eleme e = new eleme();
		for(int i=0;i<m;i++) {
			x = sc.nextInt();
			y = sc.nextInt();
			map[x][y]=1;
			map[y][x]=1;
		}
		
		Queue<Integer>q = new LinkedList<Integer>();

		q.add(1);
		visited[1]=true;
		while(!q.isEmpty()) {
			int rc= q.poll();
			
			for(int i=1;i<=n;i++) {
				if(map[rc][i]==1&&!visited[i]) {
					q.add(i);
					visited[i]=true;
					res++;
				}
			}
		}
		System.out.println(res-1);
		
	}
}

