class lab1
{
    public static void main(String[] args)
    {
		// first part of the lab: printing name 
        String fName, frstName, lName, space;
    	fName = new String("Marwin Gonzales");
    	space = new String (" ");
    	
    	frstName = fName.substring(0,fName.indexOf(space));
    	lName = fName.substring(fName.indexOf(space)+1, fName.length());
    	
    	System.out.println("Your full name is: " + fName);
    	System.out.print("Or more formally: ");
    	System.out.println(lName + "," +space + frstName); 
		/* changed fName to frstName because I got an issue (not necessarily an error) 
		where my IDE tells me that "The value of the local variable frstName is not used" 
		so I decided to replace fName with frstName where it would make the most sense */


		// second part of lab: printing face (edited to align face)
		System.out.println("    ///// \n" +			// hair
						   "  |  o o  | \n" +		// eyes
						   "( |   ^   | ) \n" +		// nose
						   "  |  [_]  | \n" +		// mouth
						   "    -----");			// chin
		/* testing out
		the multiple
		line comment */
    }
}
