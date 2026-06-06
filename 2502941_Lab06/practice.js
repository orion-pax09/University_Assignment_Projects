const choices = ["Paper","Scissor","Rock"];
const player = choices[Math.floor(Math.random()*3)];
const computer = choices[Math.floor(Math.random()*3)];
console.log("Player choose: ",player);
console.log("Computer choose: ",computer);
if (computer === player){
  console.log("Draw");
}
else if((player==="Rock" && computer==="Scissor") || (player==="Paper" && computer==="Rock") || (player==="Scissor" && computer==="Paper"))
{
  console.log("Player won");
}
else{
  console.log("Computer won");
}

