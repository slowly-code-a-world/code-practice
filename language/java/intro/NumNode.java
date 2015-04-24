public class NumNode {
	private static NumNode Nodes = null;
	
	int Value;
	
	NumNode Next;
	
	public NumNode(int V) {
		Value = V;
		Next = null;	
	}	
	public static NumNode Head() {
		return Nodes;
	}
	public void Insert() {
		if (null == Nodes) {
			Nodes = this;
			return;
		}

		if (Value < Nodes.Value) {
			Next = Nodes;
			Nodes = this;
			return;
		}

		if (null == Nodes.Next) {
			Nodes.Next = this;
			return;
		}

		NumNode p = Nodes;
		while (null !=p.Next && p.Next.Value < Value) p = p.Next;
		if (null == p.Next) {
			p.Next = this;
		} else {
			Next = p.Next;
			p.Next = this;
		}
	
		return;	
	}
	public static void PrintList() {
		if (null == Nodes) return;
		for (NumNode N = Nodes; N != null; N = N.Next)
			System.out.println(N.Value);
	}
}
