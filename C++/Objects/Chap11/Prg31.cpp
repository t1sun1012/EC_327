/**************************************************************
 * The application file to test the Tokenizer class           *
 **************************************************************/

#include "tokenizer.h"

int main ( )
{
  // The target string that needs to be tokenized
  string target ("This is the string to be tokenized. \n");

  // The delimit string defines the set of separators
  string delimit (" \n");     // Delimiter made of ’ ’ and ’\n’

  // Instantiation of tokenizer object 	
  Tokenizer tokenizer (target, delimit);
   
  // Traversing the target string to find tokens	
  while (tokenizer.moreToken ())
  {
    cout << tokenizer.nextToken () << endl;
  }
  return 0;
}
	