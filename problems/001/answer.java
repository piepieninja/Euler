//package 001;

public class answer {
    public static void main(String[] args) {
	int ret = 0;
	for (int i = 0; i < 1000; i++){
	    if (i % 3 == 0 || i % 5 == 0){
		ret += i;
	    }
	}

	System.out.println("answer: " + ret);	
    }
}
