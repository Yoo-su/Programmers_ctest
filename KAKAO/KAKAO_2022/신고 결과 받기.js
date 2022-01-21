function solution(id_list, report, k) {
    const answer = [];
    
    const info={};
    const res={};

    id_list.forEach(id=>{
        info[id]=new Set();
        res[id]=0;
    })
    
    report.forEach(r=>{
        const tmp=r.split(' ')
        info[tmp[1]].add(tmp[0])
    })
    
    id_list.forEach(id=>{
        if (info[id].size>=k){
            info[id].forEach(name=>{
                res[name]+=1;
            })
        }
    })

    return Object.values(res);
}
