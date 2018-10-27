//FATAL : NOT FOR DEPLOYMENT
// FATAL : THIS PROGRAM IS CURRENTLY IN DEVELOPMENT PHASE AND CONTAINS A LOT OF ERRORS. PLEASE USE WITH CAUTION AND REPORT ANY ERRORS IF FOUND.

// Not checked for pointers in any form of equivalence
// Not checked for equivalence when typedef is present
// Not checked for functional equivalence
// Not checked array length in internal name equivalence
// Not checked array equivalence in structural equivalence
// Not checked for pointer equivalence inside structures

#include<bits/stdc++.h>

using namespace std;

string s[100][100];
int x = 0;

void nameeq(string a, string b) {
	string adt, bdt;
	int i, j;
	for(i = 0; i < x; i++) {
		j = 0;
		while(s[i][j] != "") {
			if(s[i][j++] == a) {
				adt = s[i][0];
				break;
			}
		}
	}

	for(i = 0; i < x; i++) {
		j = 0;
		while(s[i][j] != "") {
			if(s[i][j++] == b) {
				bdt = s[i][0];
				break;
			}
		}
	}

	if(adt == bdt)
		cout<< a << " and " << b << " are name equivalent.\n";
	else
		cout<< a << " and " << b << " are not name equivalent.\n";
}

void internalnameeq(string a, string b) {
	string store_a = a, store_b = b;
	
	a += "[";
	b += "[";

	string adt, bdt;string temp_a, temp_b;
	smatch match_a;smatch match_b;
	int i, j, flag = 0, store_line_a = 0, store_line_b = 0;
	for(i = 0; i < x; i++) {
		flag = 0;
		j = 0;
		while(s[i][j] != "") {
			if (s[i][j].rfind(a, 0) == 0) {
				const string a_size = s[i][j];
				std::regex rgx(".*\\[(\\w+)\\]");

			    if (std::regex_search(a_size.begin(), a_size.end(), match_a, rgx)) {
			        // std::cout << "match: " << match_a[1] << '\n';
			    }
			    // cout<<"match_a[1] : "<<match_a[1]<<endl;
			    temp_a = match_a[1];
				adt = s[i][0];
				flag = 1;
				store_line_a = i;
				break;
			}
			j++;
		}
		if(flag == 1)
			break;
	}

	for(i = 0; i < x; i++) {
		flag = 0;
		j = 0;
		while(s[i][j] != "") {
			if (s[i][j].rfind(b, 0) == 0) {
				const string b_size = s[i][j];
				std::regex rgx(".*\\[(\\w+)\\]");

			    if (std::regex_search(b_size.begin(), b_size.end(), match_b, rgx)) {
			        // std::cout << "match: " << match_b[1] << '\n';
			    }
			    // cout<<"match_b[1] : "<<match_b[1]<<endl;
			    temp_b = match_b[1];
				bdt = s[i][0];
				flag = 1;
				store_line_b = i;
				break;
			}
			j++;
		}
		if(flag == 1)
			break;
	}
	// cout<<"temp_a : "<<temp_a<<" and temp_b : "<<temp_b<<endl;
	if(temp_a != temp_b) {
		cout<< store_a << " and " << store_b << " are not internal name equivalent.\n";
		return;
	}

	if(adt == bdt && store_line_a == store_line_b)
		cout<< store_a << " and " << store_b << " are internal name equivalent.\n";
	else
		cout<< store_a << " and " << store_b << " are not internal name equivalent.\n";
}

void typedefeq(string a, string b) {
	string adt, bdt, line = "", line1 = "", store_a = a, store_b = b;
	int i, j, flag, prev_i = 9999999;
	while(1 == 1) {
		flag = 0;
		for(i = 0; i < x; i++) {
			j = 0;
			while(s[i][j] != "") {
				if((s[i][j] == a) && (i < prev_i)) {
					flag = 1;
					adt = s[i][0];
					a = adt;
					prev_i = i;
					break;
				}
				j++;
			}
		}
		if(flag == 0)
			break;
	}

	if(adt == "typedef") {
		adt = "";
		j = 0;
		int temp = 0;
		while(s[prev_i][j++] != "") {
			temp++;
		}
		temp -= 2;
		while(temp > 0) {
			adt += s[prev_i][temp];
			temp--;
		}
	}

	prev_i = 9999999;

	while(1 == 1) {
		flag = 0;
		for(i = 0; i < x; i++) {
			j = 0;
			while(s[i][j] != "") {
				if((s[i][j] == b) && (i < prev_i)) {
					flag = 1;
					bdt = s[i][0];
					b = bdt;
					prev_i = i;
					break;
				}
				j++;
			}
		}
		if(flag == 0)
			break;
	}

	if(bdt == "typedef") {
		bdt = "";
		j = 0;
		int temp = 0;
		while(s[prev_i][j++] != "") {
			temp++;
		}
		temp -= 2;
		while(temp > 0) {
			bdt += s[prev_i][temp];
			temp--;
		}
	}
	cout<<"adt : "<<adt<<" and bdt : "<<bdt<<endl;
	if(adt == bdt)
		cout<< store_a << " and " << store_b << " are structural equivalent.\n";
	else
		cout<< store_a << " and " << store_b << " are not structural equivalent.\n";
}

void structeq(string a, string b, string str1) {
	string line = "";

	string s[100][100]; //PLEASE MODIFY IT LATER AS VARIABLE NAME IS SAME

	int y = 0, i, j = 0, flag = 0;

	for(i = 0; i < str1.length(); i++) {
		if(str1[i] == ' ' || str1[i] == ',') {
			if(flag != 0) {
				s[x][y++] = line;
				line = "";
				flag = 0;
			}
		}
		else if(str1[i] == ';') {
			s[x][y++] = line;
			s[x][y] = ""; 
			x++;
			y = 0;
			line = "";
			flag = 0;
		}
		else if(str1[i] == '{') {
			s[x][y++] = line;
			s[x][y++] = "{";
			s[x][y] = ""; 
			x++;
			y = 0;
			line = "";
			flag = 0;
		}
		else {
			line += str1[i];
			flag++;
		}
	}

	// for(i = 0; i < x; i++) {
	// 	j = 0;
	// 	while(s[i][j] != "") {
	// 		cout<<s[i][j++]<<" ------------------ ";
	// 	}
	// 	cout<<"\n";
	// }

	string str[100][100];
	string dt[100];
	int ind_str = 0, ind_dt = 0, int_ind_str = 0;

	for(i = 0; i < x; i++) {
		j = 0;
		while(s[i][j] != "") {
			j++;
		}
		if(s[i][0] == "struct" && s[i][j-1] == "{") {
			dt[ind_dt++] = s[i][1];
			str[ind_str][0] = s[i][1];
			i++;int_ind_str = 1;
			while(s[i][0] != "}") {
				if(s[i][0] == "struct") {
					str[ind_str][int_ind_str++] = s[i][1];
				}
				else {//cout<<"s[i][0] : "<<s[i][0]<<endl;
					str[ind_str][int_ind_str++] = s[i][0];
				}
				i++;
			}
			ind_str++;
		}
	}

	// for(i = 0; i < ind_str; i++) {
	// 	j = 0;
	// 	while(str[i][j] != "") {
	// 		cout<<str[i][j++]<<" == ";
	// 	}
	// 	cout<<"\n";
	// }

	// for(i = 0; i < ind_dt; i++) {
	// 	cout<<dt[i]<<" ";
	// }

	// cout<<endl;

	int l = ind_dt;

	int tab[l][l];

	i = 0; j = 0;
	for(i = 0; i < l; i++) {
		for(j = 0; j < l; j++) {
			tab[i][j] = 1;
		}
	}

	flag = 0;
	while(flag == 0) {
		flag = 1;
		for(i = 0; i < l; i++) {
			for(j = 0; j < l; j++) {
				if(i == j) {

				}
				else {
					int li = 0, lj = 0;

					while(str[i][li] != "") {
						li++;
					}
					//cout<< "li : " << li <<endl;
					while(str[j][lj] != "") {
						lj++;
					}
					//cout<< "lj : " << lj << endl;

					if(li != lj) {
						tab[i][j] = 0;
						tab[j][i] = 0;
						flag = 0;
						break;
					}
					else {
						int x = 1;

						while(x < li) {
							if(str[i][x] == str[j][x]) {
								
							}
							else {
								int int_flag = 0;
								char p = str[i][x][str[i][x].length() - 1];
								char q = str[j][x][str[j][x].length() - 1];

								if((p == '*') && (q == '*')) {
									string sp = "", sq = "";

									int t = 0;

									for(t = 0; t < str[i][x].length() - 1; t++) {
										sp += str[i][x][t];
									}

									for(t = 0; t < str[j][x].length() - 1; t++) {
										sq += str[j][x][t];
									}

									int temp_i = 0, temp_j = 0;
									for(t = 0; t < l; t++) {
										if(dt[t] == sp) {
											temp_i = t;
										}
										else if(dt[t] == sq) {
											temp_j = t;
										}
									}
									if(tab[temp_i][temp_j] == 1) {
										int_flag = 1; //For breaking out of outer while loop
										break;
									}
									else if(tab[i][j] != 0) {
										tab[i][j] = 0;
										tab[j][i] = 0;
										flag = 0;
										break;
									}

								}
								else if(tab[i][j] != 0) {
									tab[i][j] = 0;
									flag = 0;//cout<<"Hey  there : \n";
								}

								if(int_flag == 1) {
									break;
								}
							}
							x++;
						}
					}
				}
			}
		}
		if(flag == 1) {
			break;
		}
	}

	// for(i = 0; i < l; i++) {
	// 	for(j = 0; j < l; j++) {
	// 		cout<<tab[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	string adt = "", bdt = "";
	for(i = 0; i < x; i++) {
		j = 0;
		while(s[i][j] != "") {
			if(s[i][j++] == a) {
				adt = s[i][1];
				break;
			}
		}
	}

	for(i = 0; i < x; i++) {
		j = 0;
		while(s[i][j] != "") {
			if(s[i][j++] == b) {
				bdt = s[i][1];
				break;
			}
		}
	}

	int res_i = 0, res_j = 0;//cout<<"ind_dt : "<<ind_dt<<endl;cout<<"adt : "<<adt<<" bdt : "<<bdt<<endl;
	for(i = 0; i < ind_dt; i++) {
		if(dt[i] == adt) {
			res_i = i;
		}
		if(dt[i] == bdt) {
			res_j = i;
		}
	}
	//cout<<"res_i : "<<res_i<<"   res_j : "<<res_j<<endl;
	if(tab[res_i][res_j] == 1) {
		cout<<a<<" and "<<b<<" are structural equivalent\n";
	}
	else {
		cout<<a<<" and "<<b<<" are not structural equivalent\n";
	}
}

void funceq(string a, string b, string str1) {

	string line = "";
	string s[100][100] ; //PLease change it later as variable name is same

	int y = 0, i, j = 0, flag = 0;

	for(i = 0; i < str1.length(); i++) {
		if(str1[i] == ' ' || str1[i] == ',') {
			if(flag != 0) {
				s[x][y++] = line;
				line = "";
				flag = 0;
			}
		}
		else if(str1[i] == ';') {
			s[x][y++] = line;
			s[x][y] = ""; 
			x++;
			y = 0;
			line = "";
			flag = 0;
		}
		else if(str1[i] == '(') {
			s[x][y++] = line;
			s[x][y++] = "(";
			s[x][y] = ""; 
			x++;
			y = 0;
			line = "";
			flag = 0;
		}
		else if(str1[i] == ')') {
			s[x][y++] = line;
			s[x][y] = ""; 
			x++;
			y = 0;
			s[x][0] = ")";
			s[x][1] = "";
			x++;
			i++;
			line = "";
			flag = 0;
		}
		else {
			line += str1[i];
			flag++;
		}
	}

	// for(i = 0; i < x; i++) {
	// 	j = 0;
	// 	while(s[i][j] != "") {
	// 		cout<<s[i][j++]<<" ------------------ ";
	// 	}
	// 	cout<<"\n";
	// }

	string rt[100]; int rt_index = 0;
	string funcname[100]; int fn_index = 0;
	string str[100][100]; int str_index = 0;

	for(i = 0; i < x; i++) {
		j = 0;
		while(s[i][j] != "") {
			if(s[i][j] == "(") {
				rt[rt_index++] = s[i][0];
				funcname[fn_index++] = s[i][1];
				i++;
				int temp = 0;
				while(s[i][0] != ")") {
					int int_temp = 0;
					while(s[i][int_temp] != "") {
						str[str_index][temp++] = s[i][int_temp];
						int_temp += 2;
					}
					i++; 
				}
				str_index++;
				break;
			}
			j++;
		}
	}

	// for(i = 0; i < rt_index; i++) {
	// 	cout << rt[i] << " ";
	// }

	// cout<<endl;

	// for(i = 0; i < fn_index; i++) {
	// 	cout << funcname[i] << " ";
	// }

	// cout<<endl;

	// for(i = 0; i < str_index; i++) {
	// 	j = 0;
	// 	while(str[i][j] != "") {
	// 		cout<<str[i][j]<<" ";
	// 		j++;
	// 	}
	// 	cout<<endl;
	// }

	int ind_a = 0, ind_b = 0;
	for(i = 0; i < fn_index; i++) {
		if(funcname[i] == a) {
			ind_a = i;
		}
		if(funcname[i] == b) {
			ind_b = i;
		}
	}

	//Checking return types

	if(rt[ind_a] != rt[ind_b]) {
		cout<<a<<" and "<<b<<" are not structural equivalent \n";
		return;
		//Add return here for void type
	}
	else {
		i = 0;
		int la = 0, lb=  0;
		while(str[ind_a][i] != "") {
			la++;
			i++;
		}
		i = 0;
		while(str[ind_b][i] != "") {
			lb++;
			i++;
		}
		if(la != lb) {
			cout<<a<<" and "<<b<<" are not structural equivalent \n";
			return;
		}
		else{
			i = 0;
			for(i = 0; i < la; i++) {
				if(str[ind_a][i] != str[ind_b][i]) {
					cout<<a<<" and "<<b<<" are not structural equivalent \n";
					return;
				} 
			}
		}
	}
	cout<<a<<" and "<<b<<" are structural equivalent \n";
}

int main() {
	string str = "";
	string str_structeq = "";

	while (1 == 1)
	{
	    string line;
	    getline(cin, line);

	    if(line == "") {
	    	break;
	    }
	    str = str + line;
	    str_structeq = str_structeq + " " + line;
	}

	string line = "";

	int y = 0, i, j = 0, flag = 0;

	for(i = 0; i < str.length(); i++) {
		if(str[i] == ' ' || str[i] == ',') {
			if(flag != 0) {
				s[x][y++] = line;
				line = "";
				flag = 0;
			}
		}
		else if(str[i] == ';') {
			s[x][y++] = line;
			s[x][y] = ""; 
			x++;
			y = 0;
			line = "";
			flag = 0;
		}
		else {
			line += str[i];
			flag++;
		}
	}

	// for(i = 0; i < x; i++) {
	// 	j = 0;
	// 	while(s[i][j] != "") {
	// 		cout<<s[i][j++]<<" ------------------ ";
	// 	}
	// 	cout<<"\n";
	// }

	int num;
	string a, b;
	cout<<"Enter values to compare : \n";
	cin>>a;
	cin>>b;

	for(i = 0; i < x; i++) {
		j = 0;
		while(s[i][j] != "") {
			if(s[i][j] == a) {
				if(s[i][0] == "struct") {
					num = 3;
				}
				else {
					num = 1;
				}
				break;
			}
			else {
				string temp_string = a + "\\[.*";
				regex tempregex(temp_string);
				if(regex_search(s[i][j], tempregex)) {
					num = 2;
					break;
				}
				else {
					string temp_string2 = a + "\\(.*";
					regex tempregex2(temp_string2);
					if(regex_search(s[i][j], tempregex2)) {
						num = 4;
						break;
					}
				}
			}
			j++;
		}
	}
	// cout<<num<<endl;
	switch(num) {
		case 1 : 
			nameeq(a, b);
			break;

		case 2 : 
			internalnameeq(a, b);
			break;

		case 3 : 
			structeq(a, b, str_structeq);
			break;

		case 4 : 
			funceq(a, b, str_structeq);
			break;

		default : 
			cout<<"Wrong entry\n";
	}

	return 0;
}