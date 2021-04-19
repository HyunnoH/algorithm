function dfs(graph, v, visited) {
    visited[v] = true;
    const n = graph.length;
    
    for(let i = 0; i < n; i+=1) {
        if(graph[v][i] && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

function solution(n, computers) {
    var answer = 0;
    let visited = [];
    for(let i = 0; i < n; i+=1) {
        visited.push(false);
    }
    
    for(let i = 0; i < n; i+=1) {
        if(!visited[i]) {
            dfs(computers, i, visited);
            answer += 1;
        }
    }
    return answer;
}
