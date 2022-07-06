import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Heap_DDOROREE {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		minHeap heap = new minHeap();
		
		for( int i=0;i<N;i++ ){
			int val = Integer.parseInt(br.readLine());
			
			if( val==0 ){
				System.out.println( heap.delete() );
				continue;
			}
			heap.insert(val); 
		}
	}
	
	public static class minHeap{
		private ArrayList<Integer> heap;
		
		public minHeap(){
			super();
			this.heap = new ArrayList<>();
			heap.add(0); // 인덱스 0 채우기 - 1부터 시작하기 위함
		}

		public void insert(int val) {
			heap.add(val);
			int p = heap.size() - 1; // 왜지. 아 루트.? - 마지막에 있는 값을 찾고
			
			while( p>1 && heap.get(p/2) > heap.get(p) ){ // 자식노드 위치 N에서의 부모노드 인덱스 = N/2 
				System.out.println( "교환" );
				
				// 부모노드 > 자식노드 => 교환 (최소힙이라서)
				int tmp = heap.get(p/2);
				heap.set( p/2, heap.get(p) );
				heap.set( p, tmp );
				
				p /= 2; // p를 부모 값으로 변경 (부모 인덱스로 이동)
			}
		}
		
		// 삭제할 때는 재귀..
		public int delete() {
			if( heap.size()-1<1 ) { //힙사이즈가 0..이면 삭제할 애가 없으니까
				return 0;
			}
			
			int currentIndex = 1;
			int target = heap.get(1); // 삭제 타겟 = 루트노드
			
			/* 원래 루트값은 삭제하고 맨 밑에 값을 새로 넣고 맨 밑에 노드 삭제 */
			heap.set( 1, heap.get(heap.size()-1) );
			heap.remove( heap.size()-1 );
			
			/* 루트에 올린 값을 내리면서 전체 노드와 비교하면서 전체 노드 재정렬 */
			while( currentIndex*2 < heap.size() ){
				int minIndex = currentIndex*2;
				int min = heap.get( minIndex );
				
				if( minIndex+1<heap.size() && min>heap.get(minIndex+1) ){
					min = heap.get(minIndex+1);
					minIndex++;
				}
				
				if( heap.get(currentIndex) < min ){
					break;
				}
				
				/* 부모-자식 노드 교환 */
				int tmp = heap.get(currentIndex);
				heap.set( currentIndex, heap.get(minIndex) );
				heap.set( minIndex, tmp );
				currentIndex = minIndex;
			}
			
			return target;
		}
		
	}
	
}

