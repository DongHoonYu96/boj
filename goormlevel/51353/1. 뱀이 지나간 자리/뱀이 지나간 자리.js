// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let n,m;
	let ret=[];
	let flag=1;
	
	for await (const line of rl) {
		//console.log(line);
		[n,m]=line.split(" ");
		rl.close();
	}

	
	for(let i =0;i<n;++i){
		if(i%2==0){
				console.log("#".repeat(m));
			}
			else{
				if(flag==1){
					console.log(".".repeat(m-1)+"#");
				}
				else{
					console.log("#"+".".repeat(m-1));
				}
				flag=!flag;
				
			}
	}
	console.log(ret.join(''));
	process.exit();
})();
