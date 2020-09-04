import java.util.* ;
public class Main {
	public static void main(String[] args) {
		Scanner input  = new Scanner(System.in);
		int iter, N, L;
		int[] cost;
		
		iter = input.nextInt();
		for(int i=0;i<iter;i++) {
			N = input.nextInt();
			L = input.nextInt();
			double minAvg = 101;
			double Avg;
			
			cost = new int[N];
			
			for(int j=0;j<N;j++) {
				cost[j] = input.nextInt();
			}
			
			for(int j=0;j<N;j++) {
				int sum = 0;
				int count = 0;
				
				for(int k=j;k<N;k++) {
					sum = sum + cost[k];
					count++;
					
					if(count<L) {
						continue;
					}
					
					Avg = (double)sum / count;
					
					if(Avg < minAvg) {
						minAvg = Avg;
					}
				}
			}
			System.out.printf("%.11f ", minAvg);
		}
	}
}
