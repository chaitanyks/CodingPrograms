function createPhoneNumber(numbers){
  var format = "(xxx) xxx-xxxx";
  numbers.forEach((value)=>{
    format = format.replace('x',value);
  })
  return format;
}
