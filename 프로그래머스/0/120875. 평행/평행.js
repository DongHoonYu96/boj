function solution(dots) {
    let answer = 0;
    let comb=[[0,1],[0,2],[0,3],[1,2],[1,3],[2,3]];

    for (com of comb){
        //console.log(com);
        let remain=[];
        let vis = [0,0,0,0];
        for(i of com){
            vis[i]=1;
        }
        for(let i=0;i<4;++i){
            if(vis[i]) continue;
            remain.push(i);
        }
        //console.log("remain : "+  remain);
        // console.log(dots[com[0]][0] , dots[com[1]][0])
        // console.log(dots[com[0]][1] , dots[com[1]][1])
        // console.log(dots[remain[0]][0] , dots[remain[1]][0])
        // console.log(dots[remain[0]][1] , dots[remain[1]][1])
        let m1 = (dots[com[0]][1] - dots[com[1]][1]) /  (dots[com[0]][0] - dots[com[1]][0]) ;
        let m2 = (dots[remain[0]][1] - dots[remain[1]][1]) / (dots[remain[0]][0] - dots[remain[1]][0]);
        //console.log(m1, m2);
        //console.log(m2);
        if(m1==m2) answer=1;
    }
    return answer;
}