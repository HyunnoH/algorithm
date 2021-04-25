class UnionFind {
    tree = [];
    
    constructor(n) {
        for(let i = 0; i < n; i+=1) {
            this.tree.push(i);
        }
    }
    
    union(x, y) {
        x = this.find(x);
        y = this.find(y);
        
        if(x > y) {
            this.tree[x] = y;
        } else {
            this.tree[y] = x;
        }
    }
    
    find(x) {
        if(this.tree[x] === x) {
            return x;
        }
        return this.find(this.tree[x]);
    }
}

function solution(n, costs) {
    var answer = 0;
    
    costs.sort((prev, next) => prev[2] - next[2]);
    
    const union = new UnionFind(costs.length);
    
    for(let i = 0; i < costs.length; i+=1) {
        const now = costs[i];
        
        if(union.find(now[0]) !== union.find(now[1])) {
            answer += now[2];
            union.union(now[0], now[1]);
        }
    }
    
    
    return answer;
}
