#include "std_lib_facilities_4.h"
#include <iostream>
#include <algorithm>

struct jPair{
	string first;
	double second;
	jPair(string s, int v): first(s), second(v){};
	
};


 void trim(string& s){
	size_t p = s.find_first_not_of(" \t");
	s.erase(0, p);

	p = s.find_last_not_of(" \t");
		if (string::npos != p)
		s.erase(p+1);
}

void trimr(string& s){
	if(s[s.size()-1] == '\r')
		s.erase(s.begin()+s.size()-1);
}


int preDefine(vector<jPair>& v){
	for(int i = 0; i <= 15; ++i){
		string a = "R";
		string b = to_string(i);
		a.append(b);
		jPair p(a, i);
		v.push_back(p);
	}
	jPair p1 ("KBD", 24576);
	jPair p2 ("SCREEN", 16384);
	jPair p3 ("SP", 0);
	jPair p4 ("LCL", 1);
	jPair p5 ("ARG", 2);
	jPair p6 ("THIS", 3);
	jPair p7 ("THAT", 4);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	v.push_back(p7);
	return 0;
}

vector<int> binaryA(int n){
	vector<int> ans;
	while(n>1){
		ans.push_back(n%2);
		n=n/2;
	}
	ans.push_back(n%2);
	for(int i = ans.size(); i < 16; ++i)
		ans.push_back(0);
	reverse(ans.begin(), ans.end());
	return ans;
}

jPair parseParen(string s, int line){
	string name ="";
	int w = 1;
	
	if(s[0] == '('){
		while(s[w]!= ')'){
			name = name+s[w];
			w++;
		}
		jPair p(name, line);
		return p;
	}
	jPair p(name, line);
	return p;
}

jPair parseAt(string s, int index){	
	string name = "";
	if(s[0] == '@'){
		if(isalpha(s[1])){
			if(s.size() == 2 && ((s[1] == 'A') || (s[1] == 'D') || (s[1] == 'M')))
				cout<<"";
			else
				if(s.size()>2){
					for(int i = 1; i < s.length(); ++i){
						name=name+s[i];	
					}
					trim(name);
					jPair p(name, index);
					return p;
				}
				else{
					name = name+s[1];
					jPair p(name, index);
					return p;
				}
		}
			
	}
	
		
	jPair p(name, index);
	return p;
}


void decomment (vector<string>& a){
	for(int i = a.size()-1; i >=0; --i)
		if(a[i].size() ==0)
			a.erase(a.begin()+i);
	for(int i = a.size()-1; i >=0; --i)
		if(a[i].size()!= 0)
		if((a[i][0] == '/' && a[i][1] == '/'))
			a.erase(a.begin()+i);
	
	for(int i = a.size()-1; i >=0; --i)
		for(int j = 0; j < a[i].size(); j++)
			if(a[i][j] == '/')
				a[i].erase(a[i].begin()+j, a[i].end());
	
}	


void delabel (vector<string>& a){
	for(int i = a.size()-1; i >=0; --i)
		if(a[i][0] == '(')
			a.erase(a.begin()+i);
	
}	
	
pair<bool, int> check(vector<jPair> a, string b){
	for(int i = 0; i < a.size(); ++i)
		if(a[i].first ==b){
			pair<bool, int> p(true, a[i].second);
			return p;
		}
}


//parse it to look for = and ;


string cInstruc(string d, string c, string j){
	string cIns = "";
	string begin = "111";
	string a;
	string comp;
	string dest;
	string jump;
	if(c == "0"){
		a = "0";
		comp = "101010";
	}
	if(c == "1"){
		a = "0";
		comp = "111111";
	}
	if(c == "-1"){
		a = "0";
		comp = "111010";
	}
	if(c == "D"){
		a = "0";
		comp = 	"001100";
	}
	if(c == "A"){
		a = "0";
		comp = "110000";
	}
	if(c == "!D"){
		a = "0";
		comp = "001101";
	}
	if(c == "!A"){
		a = "0";
		comp = "110001";
	}
	if(c == "-D"){
		a = "0";
		comp = "001111";
	}
	if(c == "-A"){
		a = "0";
		comp = "110011";
	}
	if(c == "D+1"){
		a = "0";
		comp = "011111";
	}
	if(c == "A+1"){
		a = "0";
		comp = "110111";
	}
	if(c == "D-1"){
		a = "0";
		comp = "001110";
	}
	if(c == "A-1"){
		a = "0";
		comp = "110010";
	}
	if(c == "D+A"){
		a = "0";
		comp = "000010";
	}
	if(c == "D-A"){
		a = "0";
		comp = "010011";
	}
	if(c == "A-D"){
		a = "0";
		comp = "000111";
	}
	if(c == "D&A"){
		a = "0";
		comp = "000000";
	}
	if(c == "D|A"){
		a = "0";
		comp = "010101";
	}
	if(c == "M"){
		a = "1";
		comp = "110000";
	}
	if(c == "!M"){
		a = "1";
		comp = "110001";
	}
	if(c == "-M"){
		a = "1";
		comp = "110011";
	}
	if(c == "M+1"){
		a = "1";
		comp = "110111";
	}
	if(c == "M-1"){
		a = "1";
		comp = "110010";
	}
	if(c == "D+M"){
		a = "1";
		comp = "000010";
	}
	if(c == "D-M"){
		a = "1";
		comp = "010011";
	}
	if(c == "M-D"){
		a = "1";
		comp = "000111";
	}
	if(c == "D&M"){
		a = "1";
		comp = "000000";
	}
	if(c == "D|M"){
		a = "1";
		comp = "010101";
	}
	if(d == "null"){
		dest = "000";
	}
	if(d == "M"){
		dest = "001";
	}
	if(d == "D"){
		dest = "010";
	}
	if(d == "MD"){
		dest = "011";
	}
	if(d == "A"){
		dest = "100";
	}
	if(d == "AM"){
		dest = "101";
	}
	if(d == "AD"){
		dest = "110";
	}
	if(d == "AMD"){
		dest = "111";
	}
	if(j == "null"){
		jump = "000";
	}
	if(j == "JGT"){
		jump = "001";
	}
	if(j == "JEQ"){
		jump = "010";
	}	
	if(j == "JGE"){
		jump = "011";
	}
	if(j == "JLT"){
		jump = "100";
	}
	if(j == "JNE"){
		jump = "101";
	}
	if(j == "JLE"){
		jump = "110";
	}
	if(j == "JMP"){
		jump = "111";
	}
	
	cIns.append(begin);
	cIns.append(a);
	cIns.append(comp);
	cIns.append(dest);
	cIns.append(jump);
	return cIns;
}

vector<string> parseC(string s){
	string dest = "";
	string comp = "";
	string jump = "";
	int ep =0;
	int sp =0;
	bool ie = false;
	bool is = false;
	vector<string> equation; 
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '='){
			ie = true;
			ep = i;
		}
	}
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == ';'){
			is = true;
			sp = i;
		}
	}
	
	if(ie == true && is == true){
		for(int i = 0; i < ep; ++i)
			dest = dest + s[i];
		for(int i = ep+1; i < sp; ++i)
			comp = comp +s[i];
		for(int i = sp+1; i < s.size(); ++i)
			jump = jump + s[i];
	}
	
	
	if(ie == true && is == false){
		jump = "null";
		for(int i = 0; i < ep; ++i)
			dest = dest + s[i];
		for(int i = ep+1; i < s.length(); ++i)
			comp = comp +s[i];
	}
	
	if(ie == false && sp == true){
		dest = "null";
		for(int i = 0; i < sp; ++i)
			comp = comp +s[i];
		for(int i = sp+1; i < s.size(); ++i)
			jump = jump + s[i];
	}
	
	equation.push_back(dest);
	equation.push_back(comp);
	equation.push_back(jump);
	return equation;
	
}	
	
vector<int> convert(string s){
	vector<int> ans;
	for(int i = 0; i < s.size(); ++i)
		ans.push_back((s[i])-'0');
	return ans;
}




int main(){
//===========================================================================
	vector<vector<int>> finalHack;
	int hackIndex = 0;
	int index = 15;
	int line = 0;
	vector<string> code;
	vector<jPair> symbolTable;
	preDefine(symbolTable);
	cout<<"What is the name of the file you want to input?"<<endl;
	string filename;
	cin>>filename;
	ifstream ist (filename);
	while(!ist.eof()){
		string codeLine;
		getline(ist, codeLine);
		code.push_back(codeLine);
	}
	

//===========================================================================
//===========================================================================
	

	for(int i= 0; i < code.size(); ++i)
		trimr(code[i]);
		decomment(code);
	
	for(int i= 0; i < code.size(); ++i)
		trim(code[i]);

	
	
	
//==============================================================================
//==============================================================================
	for(int i = 0; i<code.size(); ++i){
		if(code[i][0] != '(')
			line++;
		if(parseParen(code[i], line).first != ""){
			pair<bool, int> temp = check(symbolTable, parseParen(code[i], line).first);
			if(!(temp.first)){
				symbolTable.push_back(parseParen(code[i], line));	
			}
			else if(parseParen(code[i], line).second < temp.second)
				symbolTable[temp.second].second = parseParen(code[i], line).second;
		}
	}


	for(int i = 0; i<code.size(); ++i){
		if(parseAt(code[i], index).first != ""){
			pair<bool, int> temp = check(symbolTable, parseAt(code[i], index).first);
			if(!(temp.first)){
				index++;
				symbolTable.push_back(parseAt(code[i], index));
				
			}
		//	else if(parseAt(code[i], index).second < temp.second)
			//	symbolTable[temp.second].second = parseAt(code[i], index).second;
		}
	}
	
	

	
	for(int i = 0; i < symbolTable.size(); ++i){
		cout<<symbolTable[i].first<<endl;
		cout<<symbolTable[i].second<<endl;
	}
//================================================================================
//================================================================================

	

	delabel(code);


	for(int i = 0; i < code.size(); ++i){
		if(code[i][0] == '@') {
			if(code[i][1]-'0' >-1 && code[i][1]-'0' <10){ //@<#>
				if(code[i].size()>2){
					string tempName = code[i];
					tempName.erase(tempName.begin());
					finalHack.push_back(binaryA(stoi(tempName)));
				}
				else
				finalHack.push_back(binaryA(code[i][1]-'0'));
			}
			else{
				string tempVar = code[i];
				tempVar.erase(tempVar.begin());
				for(int j = 0; j < symbolTable.size(); ++j){
					if(tempVar == symbolTable[j].first) //search
						finalHack.push_back(binaryA(symbolTable[j].second));
				}
			}
		}
		
		else{
			
			vector<string> equation = parseC(code[i]);
			vector<int> binaryC = convert(cInstruc(equation[0], equation[1], equation[2]));
			finalHack.push_back(binaryC);
		}
	}

	filename.erase(filename.end()-4, filename.end());
	filename.append(".hack");
	ofstream ost(filename);
	for(int j = 0; j< finalHack.size(); ++j){
	for(int i = 0; i <16; ++i)
		ost<<finalHack[j][i];
		ost<<endl;
	}
	
		
	/*



	*/
	
}
