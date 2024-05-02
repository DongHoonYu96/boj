#include <bits/stdc++.h>

using namespace std;

class Trie{
public: //배열0으로초기화, 0으로 초기화
    Trie() : child(), count(0){}
    void insert(string& s){
        Trie* cur = this; //root에서 시작
        for(auto c: s){ //apple추가
            cur->count++;
            if(cur->child[c-'a']==nullptr){ //자식이없으면 만듬
                cur->child[c-'a']=new Trie();
            }
            cur=cur->child[c-'a'];
        }
        cur->count++; //마지막단어
    }
    //s에 해당하는 갯수반환
    int find(string& s){
        Trie* cur = this; //root에서 시작
        for(auto c: s){ //apple찾기
            if(c=='?') return cur->count; //?면, 모든 자식수 반환하면됨.
            if(cur->child[c-'a']==nullptr){ //자식이없으면 끝냄
                return 0;
            }
            cur=cur->child[c-'a'];
        }
        return cur->count;
    }
private:
    Trie* child[26]; //문자종류갯수
    int count;
};

Trie t1[10000]; //정방향트라이 => 접두사검사
Trie t2[10000]; //역방향트라이 => 접미사를 접두사검사로 바꿈

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int>  answer;
    for(auto word : words){
        t1[word.size()-1].insert(word); //0-idxed
        reverse(word.begin(),word.end());
        t2[word.size()-1].insert(word);
    }
    for(auto query : queries){
        int ret=0;
        if(query[0]!='?'){
            ret+=t1[query.size()-1].find(query);
            answer.push_back(ret);
        }
        else{
            reverse(query.begin(),query.end());
            ret+=t2[query.size()-1].find(query);
            answer.push_back(ret);
        }
        
    }
    return answer;
}