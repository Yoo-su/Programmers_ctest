function canMove(s1,s2, length){
    let diff=0;
    for(let i=0; i<length; i++){
        if (s1[i]!==s2[i]){
            diff++;
        }
    }
    if (diff===1){
        return true
    }else{
        return false
    }
}

function solution(begin, target, words) {
    words=[begin].concat(words);
    const len=begin.length;
    const result=[];

    function dfs(node,step,visited){
        if(node===target){
            result.push(step);
            return;
        }
        if (!visited.includes(node))visited.push(node);

        const filtered=words.filter(x=>!visited.includes(x))
        
        for(let i=0;i<filtered.length;i++){
            if(canMove(node,filtered[i],len)){
                dfs(filtered[i],step+1,visited)
            }
        }
    }

    dfs(begin,0,[]);

    console.log(result)
    if (result.length===0){ return 0}
    return Math.min(...result)
}