#include<string>
#include<iostream>
#include<cctype>
#include<vector>
#include<numeric>
using namespace std
int calc_indent(string const &st):
    int num=0
    for(string::const_iterator it(st.begin());it!=st.end();++it):
        if(isspace(*it)):
            ++num
        else:
            break
    return num
string join_stack(vector<string> const &stk):
    return accumulate(stk.begin(),stk.end(),string())
void awd():
    vector<string> stk
    int gic=0
    string ln
    while(getline(cin,ln)):
        int ci=calc_indent(ln)
        if(ci>gic):
            cout<<join_stack(stk)<<"{\n"
            stk.push_back(string(ln.begin()+gic,ln.begin()+ci))
        else if(ci<gic):
            while(calc_indent(join_stack(stk))>ci):
                stk.pop_back()
                cout<<join_stack(stk)<<"}\n"
        if(!ln.empty()&&ln.back()!=':'&&ln.front()!='#'):
            cout<<ln<<';'
        else:
            if(!ln.empty()&&ln.back()==':'):
                ln.pop_back()
            cout<<ln
        cout<<'\n'
        gic=ci
    while(!stk.empty()):
        stk.pop_back()
        cout<<join_stack(stk)<<"}\n"
int main():
    return awd(),0
