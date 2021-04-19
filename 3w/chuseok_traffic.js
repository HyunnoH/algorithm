function solution(lines) {
    let answer = 0;
    let tps = 0;
    const response = [];
    
    const splitted = lines.map(line => line.split(' ').slice(1));
    
    splitted.forEach(([finishTime, durations]) => {
        const [h, m, s] = finishTime.split(':');
        const end = parseInt(h, 10) * 3600  + parseInt(m, 10) * 60 + parseFloat(s);
        const throughput = parseFloat(durations);
        const startTime = end - throughput + 0.001;
        response.push([startTime, end]);
    })
    
    response.forEach(([start, end], idx) => {
        tps = 1;
        for(let j = idx + 1; j < response.length; j+=1) {
            if(start + 1 >= response[j][0] || end+1 > response[j][0]) {
                tps+=1;
            }
        }
        
        answer = answer > tps ? answer : tps;
    })
    
    return answer;
}
