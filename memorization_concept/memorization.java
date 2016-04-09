//convert to java from python
//DO NOT FORGET TO ALLOW CAP AND NO CAP
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

    private static void game(){
	ArrayList<String> lines = read_lines("hamlet.txt");
	//	System.out.println(lines);
	int line_counter = 0;
	Scanner in = new Scanner(System.in);
	String guess = "";
	while(line_counter <= lines.size()){
	    String guess_replace = ""; 
	    String line_replace = ""; 
	    if(line_counter == 0){
		System.out.println("First Line: ");
		guess = in.nextLine();
		guess_replace = guess.replaceAll("[^a-zA-Z0-9]", "");
		line_replace = lines.get(line_counter).replaceAll("[a-zA-Z0-9]","");		
		if(line_replace == guess_replace){
		    //System.out.print(lines.get(line_counter));
		    //System.out.println(guess);
		    line_counter++;
		}
	    }
	    else if(line_counter > 0){
		System.out.println("Previous line: " + lines.get(line_counter - 1));
		System.out.println("Input next line: ");
		guess_replace = guess.replaceAll("[^a-zA-Z0-9]", "");
		line_replace = lines.get(line_counter).replaceAll("[a-zA-Z0-9]","");		
		if(line_replace == guess_replace)
		    line_counter++;
	    }
	}
    }	
    public static void main(String[] args){
	game("hamlet.txt");
	/*	String s = "zxcvlk1231p9adsf z'120!@3!234";
		System.out.println(s.replaceAll("[^a-zA-Z0-9]", ""));*/
    }
}
