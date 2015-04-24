public class Intro {
	public static void main(String[] Args) {
		
		int NumElements = Args.length;
		for (int I = 1; I <= NumElements; I++) {
			int Num;
			Num = Integer.parseInt(Args[I-1]);
			NumNode NN = new NumNode(Num);
			NN.Insert();
		}	

		System.out.println("final sorted list:");
		NumNode.PrintList();
	}	
}
