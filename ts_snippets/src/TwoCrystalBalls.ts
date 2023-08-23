// Given two crystal balls that will break if dropped from high enough
// distance, determine the exact spot in which it will break in the most
// optimized way.

// solution 1
export default function two_crystal_balls(breaks: boolean[]): number {
    
    const jmpAmount = Math.floor(Math.sqrt(breaks.length));
    let i = jmpAmount;

    for (; i < breaks.length; i+= jmpAmount) {
        if (breaks[i]) {
            break;
        }
    }

    i -= jmpAmount;

    for (let j = 0; j < jmpAmount && i <  breaks.length; ++j, ++i){
        if(breaks[i]) {
            return i;
        }

    }
    
    return -1;

}

// solution 2 - wrong
// export default function two_crystal_balls(breaks: boolean[]): number {
    
//     let lo = 0;
//     let hi = breaks.length;

//     do {

//         const m = Math.floor(lo + (hi - lo) / 2);
//         const v = breaks[m];

//         if (v === true && breaks[m-1] === false) {
//             return m;
//         } else if (v === true) {
//             hi = m;
//         } else {
//             lo = m + 1;
//         }

//     } while (lo < hi);

//     return -1;
// }