/**************************************************************
 * The implementation file for the Tokenizer class            *
 **************************************************************/

#include "tokenizer.h"

// Constructor
Tokenizer :: Tokenizer (const string& tar, const string& del)
: target (tar), delim (del)
{
  begin = target.find_first_not_of (delim, 0);
  end = target.find_first_of (delim, begin);
}


// Destructor
Tokenizer :: ~Tokenizer()
{
}


// Checks for more tokens
bool Tokenizer :: moreToken ( ) const
{
  return (begin != -1);
}


// Returns the next token
string Tokenizer :: nextToken ( )
{
  string token = target.substr (begin, end - begin);
  begin = target.find_first_not_of (delim, end);
  end = target.find_first_of(delim, begin);
  return token;
}

