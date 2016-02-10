//convert to java from python
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

class memorization{
    private static ArrayList<String> read_lines(String fname){
	ArrayList<String> return_string = new ArrayList<String>();
	try{
	    BufferedReader br = new BufferedReader(new FileReader(fname));
	    String line = null;
	    while((line = br.readLine()) != null){
		//System.out.println(line);
		return_string.add(line);
	    }
	    br.close();
	}
	catch(Exception e){
	    e.printStackTrace();
	}
	return return_string;
    }

    public static void main(String[] args){
	//System.out.println("hello world");
	ArrayList<String> temp = read_lines("hamlet.txt");
	System.out.println(temp);
    }
}
