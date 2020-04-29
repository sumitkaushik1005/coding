
public class B{
	public static void main(String[] ar){
		A a1=new A("first");
		A a2=new A("first");
		Boolean ans1=a1.equals(a2);
		System.out.println(ans1);
		Boolean ans2=(a1==a2);
		System.out.println(ans2);
	}
}
class A{
	private String value;
	A(String temp){
		this.value=temp;
	}
	public boolean equals(A a){
		if(a.getValue() ==this.value){
			return true;
		}
		else
			return false;
	}
	public String getValue(){
		return value;
	}
	public String toString(){
		return value;
	}
}