import java.io.*;
public class char_stream_file {

	 public static void main(String args[]) throws IOException {
	      FileReader in = null;
	      FileWriter out = null;

	      try {
	         in = new FileReader("inputfile.txt");
	         out = new FileWriter("outputfile.txt");
	         
	         int n;
	         while ((n = in.read()) != -1) {
	            out.write(n);
	         }
	      }
	      catch(Exception e)
	      {
	    	  e.printStackTrace();
	    	  System.out.println("Exception Found");
	      }
	      finally
	      {
	    	  try
	    	  {
	         if (in != null) {
	            in.close();
	         }
	         if (out != null) {
	            out.close();
	         }
	    	  }
	    	  catch(Exception e)
	    	  {
	    		e.printStackTrace();  
	    	  }
	      }
	   }
	}