//convert to java from python
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

class memorization{
    //Reads in file and separates into ArrayList by line
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
    private String check(String guess, String accept){
	
    }
    private void game(String fname){
	ArrayList<String> lines = read_lines(fname);
	int line_counter = 0;
	Scanner in = new Scanner(System.in);
	while(line_counter <= lines.size()){
	    if(line_counter == 0){
		System.out.println("First Line: ");
		guess = in.nextLine();
		if(guess.replaceAll('[^a-zA-Z0-9]', "") == lines.get(line_current).replaceAll('[^a-zA-Z0-9]',""))
		    line_counter++;
	    }
	    else{
		System.out.println("Previous line: " + lines.get(line_counter - 1));
		System.out.println("Input next line: ");
		guess = in.nextLine();
		if(guess.replaceAll('[^a-zA-Z0-9]', "") == lines.get(line_current).replaceAll('[^a-zA-Z0-9\]',""))
                    line_counter++;
	    }
    }	
    public static void main(String[] args){
	//System.out.println("hello world");
	ArrayList<String> temp = read_lines("hamlet.txt");
	System.out.println(temp);
    }
}
