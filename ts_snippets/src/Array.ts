// the real "array" in the nodejs environment

const array = new ArrayBuffer(6);

const array8Bit = new Uint8Array(array);
array8Bit[0] = 12;
console.log(array8Bit)

const array16Bit = new Uint16Array(array)
array16Bit[2] = 0x4512
console.log(array16Bit)