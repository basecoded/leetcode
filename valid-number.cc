class Solution {
  public:
    bool isNumber(const char *s) {
      // IMPORTANT: Please reset any member data you declared, as
      // the same Solution instance will be reused for each test case.
      string num = s;
      int i=0;
      while(num[i]==' ')i++;
      if(num[i]=='-' || num[i]=='+')i++;
      int j=num.size()-1;
      while(num[j]==' ')j--;
      if(i<=j)
        num = num.substr(i,j-i+1);
      else return false;

      int dot = -1;
      int ee = -1;
      for(int i=0; i<num.size(); i++)
      {
        if(dot == -1 && num[i] == '.')
          dot = i;
        else if(ee == -1 && num[i] == 'e'){
          ee = i;
          if(num[i+1] == '-' || num[i+1]=='+')
            i++;
        }
        else{ 
          int tmpnum = num[i]-'0';
          if(0<=tmpnum && tmpnum<=9)continue;
          else return false;
        }
      }
      //xxx.xxexx
      string startstr,midstr,laststr;
      if(dot==-1 && ee==-1){//xxxx
        startstr = num;
        if(startstr.size()<1)return false;
      }else if(dot!=-1 && ee==-1){//xxx.xxx
        startstr = num.substr(0,dot);
        midstr=num.substr(dot+1);//.1,2.,0.1,0.0,2.0
        if(startstr.size()<1 && midstr.size()<1)
          return false;
      }else if(dot==-1 && ee!=-1){//xxxexxx
        startstr = num.substr(0,ee);
        if(startstr.size()<1)return false;
        if(num[ee+1] == '-' || num[ee+1]=='+')
          laststr = num.substr(ee+2);
        else
          laststr = num.substr(ee+1);
        if(laststr.size()<1)return false;
      }else{//xxx.xxexx
        if(dot>ee)return false;
        startstr = num.substr(0,dot);
        midstr=num.substr(dot+1,ee-dot-1);
        if(startstr.size()<1 && midstr.size()<1)
          return false;
        if(num[ee+1] == '-' || num[ee+1]=='+')
          laststr = num.substr(ee+2);
        else
          laststr = num.substr(ee+1);
        if(laststr.size()<1)return false;
      }
      return true;
    }
};
