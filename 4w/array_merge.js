// Run by Node.js

const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

const arr = [];

let lineNum = 0;

rl.on("line", function(line) {
  arr.push([]);
  line.split(' ').forEach((el) => arr[lineNum].push(Number(el)));
  if(lineNum === 2) {
    rl.close();
  } else {
    lineNum += 1;
  }
}).on("close", function() {
  const result = arr[1].concat(arr[2]).sort((a, b) => a - b);
  console.log(result.join(' ') + ' ')
	process.exit();
});
