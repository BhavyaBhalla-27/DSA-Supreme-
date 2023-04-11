// https://practice.geeksforgeeks.org/problems/reverse-a-string/1

string reverseWord(string str){
    
  //Your code here
  int i = 0;
  int j = str.length() - 1;
  while(i<=j){
      swap(str[i++],str[j--]);
  }
  return str;
}
