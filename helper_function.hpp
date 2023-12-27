#include<iostream>
#include<vector>
std::vector<int>minus_one(std::vector<int>v, int pos){
    if(v.front()==0&&v.size()==1){
        return v;
    }else if(v[pos]==0){
        v[pos]=9;
        return minus_one(v,pos-1);
    }else{
        v[pos]--;
        if(v.front()==0&&v.size()>1){
            v.erase(v.begin());
        }
        return v;
    }
}

std::vector<int>ftimes(std::vector<int> a,std::vector <int>b){
    // times
    if (a.size()<b.size()){
        std::swap(a,b);
    }
    int a_size = a.size(),b_size = b.size(); 
    std::vector<std::vector<int>> res;
    for (int  i = b_size-1; i>-1;i--){
        int c = 0;
        std::vector<int> tmp;
        for (int  j = a_size-1; j>-1;j--){
            int t = b[i]*a[j]+c;
            int r = t%10;
            c = t/10;
            tmp.insert(tmp.begin(),r);
        }
        while(c>0){
            tmp.insert(tmp.begin(),c%10);
            c = c/10;
        }
        res.push_back(tmp);
    }

    for(int i = 1;i<res.size();i++){
        for(int j =0;j<i;j++){
            res[i].push_back(0);
        }
    }
// add
    int max_length = 0;
    int vec_size = res.size();
    for(int i =0;i<vec_size;i++){
        if(res[i].size()>max_length){
            max_length = res[i].size();
        }
    }
    
    for(int i =0;i<vec_size;i++){
            while(res[i].size()!=max_length){
                res[i].insert(res[i].begin(),0);
            }
    }
    std::vector<int> f_res;
    int c = 0;
    for (int j = max_length-1;j>-1;j--){
        int t = 0;
        int r = 0;
        for(int i = 0;i<vec_size;i++){
            t+=res[i][j];
        }
        t = t+c;
        c = t/10;
        r = t%10;
        f_res.insert(f_res.begin(),r);
    }
    while(c>0){
        f_res.insert(f_res.begin(),c%10);
        c = c /10;
    }
    return f_res;
}


void print(std::vector<int>s){
    for(int i =0;i<s.size();i++){
        std::cout<<s[i];
    }
    std::cout<<std::endl;
}

std::vector<int>factorial(std::vector<int>v){
        if(v.size()==1&&v.front()<=1){
            std::vector<int> res = {1};
            return res;
        }else{
            return ftimes(v,factorial(minus_one(v,v.size()-1)));
        }
}

std::vector<int>char_to_vec(std::string arg){
    std::vector<int>res;
    try{
        for(int i =0;i<arg.size();i++){
            int inp = arg[i]-'0';
            if(inp<0||inp>9){
                throw arg[i];
            }else{
                res.push_back(inp);
            }
        }
    }catch(char e){
        std::cout<<"Expect Integer>=0, get "<<e<<std::endl;
        res.clear();
    }
    return res;
}



