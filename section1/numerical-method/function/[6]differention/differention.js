const { derivative, evaluate, e } = require("mathjs")

const diffFormutla = {
  "first-derivative" : {
    "forward_finite-divided-difference" : {
      "h" : {
        '1' : 1,
        '0' : -1,
        fraction : "h" 
      },
      "h^2" : {
        '2' : -1,
        '1' : 4,
        '0' : -3,
        fraction : "2*h" 
      }
    },
    "backward_finite-divided-difference" : {
      "h" : {
        '0' : 1,
        '1' : -1,
        fraction : "h" 
      },
      "h^2" : {
        '0' : 3,
        '-1' : -4,
        '2' : 1,
        fraction : "2 * h" 
      }
    },
    "centered_finite-divided-difference" : {
      "h^2" : {
        '1' : 1,
        '-1' : -1,
        fraction : "2 * h"
      },
      "h^4" : {
        '2' : -1,
        '1' : 8,
        '-1' : -8,
        '-2' : 1,
        fraction : "12 * h"
      }
    }
  },
  "second-derivative" : {
    "forward_finite-divided-difference" : {
      "h" : {
        '2' : 1,
        '1' : 2,
        '0' : 1,
        fraction : "h^2" 
      },
      "h^2" : {
        '3' : -1,
        '2' : 4,
        '1' : -5,
        '0' : 2,
        fraction : "h^2" 
      }
    },
    "backward_finite-divided-difference" : {
      "h" : {
        '0' : 1,
        '-1' : -2,
        '-2' : 1,
        fraction : "h^2" 
      },
      "h^2" : {
        '0' : 2,
        '-1' : -5,
        '-2' : 4,
        '-3' : -1,
        fraction : "h^2" 
      }
    },
    "centered_finite-divided-difference" : {
      "h^2" : {
        '1' : 1,
        '0' : -2,
        '-1' : 1,
        fraction : "h^2"
      },
      "h^4" : {
        '2' : -1,
        '1' : 16,
        '0' : -30,
        '-1' : -16,
        '-2' : 1,
        fraction : "12 * (h ^ 2)"
      }
    }
  },
  "third-derivative" : {
    "forward_finite-divided-difference" : {
      "h" : {
        '3' : 1,
        '2' : -3,
        '1' : 3,
        '0' : -1,
        fraction : "h^3" 
      },
      "h^2" : {
        '4' : -3,
        '3' : 14,
        '2' : -24,
        '1' : 18,
        '0' : -5,
        fraction : "2 * h^3" 
      }
    },
    "backward_finite-divided-difference" : {
      "h" : {
        '0' : 1,
        '-1' : -3,
        '-2' : 3,
        '-3' : -1,
        fraction : "h^3" 
      },
      "h^2" : {
        '0' : 5,
        '-1' : -18,
        '-2' : 24,
        '-3' : -14,
        '-4' : 3,
        fraction : "2*h^3" 
      }
    },
    "centered_finite-divided-difference" : {
      "h^2" : {
        '2' : 1,
        '1' : -2,
        '-1' : 2,
        '-2' : -2,
        fraction : "2 * (h^3)"
      },
      "h^4" : {
        '3' : -1,
        '2' : 8,
        '1' : -13,
        '-1' : 13,
        '-2' : 8,
        '-3' : 1,
        fraction : "8 * (h ^ 3)"
      }
    }
  },
  "fourth-derivative" : {
    "forward_finite-divided-difference" : {
      "h" : {
        '4' : 1,
        '3' : -4,
        '2' : 6,
        '1' : -4,
        '0' : 1,
        fraction : "h^4" 
      },
      "h^2" : {
        '5' : -2,
        '4' : 11,
        '3' : -24,
        '2' : 26,
        '1' : -14,
        '0' : 3,
        fraction : "h^4" 
      }
    },
    "backward_finite-divided-difference" : {
      "h" : {
        '-4' : 1,
        '-3' : -4,
        '-2' : 6,
        '-1' : -4,
        '0' : 1,
        fraction : "h^4" 
      },
      "h^2" : {
        '-5' : -2,
        '-4' : 11,
        '-3' : -24,
        '-2' : 26,
        '-1' : -14,
        '0' : 3,
        fraction : "h^4" 
      }
    },
    "centered_finite-divided-difference" : {
      "h^2" : {
        '2' : 1,
        '1' : -4,
        '0' : 6,
        '-1' : -4,
        '-2' : 1,
        fraction : "h^4"
      },
      "h^4" : {
        '3' : -1,
        '2' : 12,
        '1' : -39,
        '0' : 56,
        '-1' : -39,
        '-2' : 12,
        '-3' : -1,
        fraction : "6 * (h ^ 4)"
      }
    }
  }
}

function differentiation(
  func,
  x,
  h,
  direction,
  accuracy,
  derivativeOrder
) {

  const result = {
    estimateResult : 0,
    func : {},
    errorPercent: 0,
    trueDerivativeResult : 0,
    trueDerivativeFuncDueToOrder : ""
  }

  const fx = {};
  const calculateFx = (i) => {
		if (i in fx) return fx[i];

		const xValue = x + (i * h);
    fx[i] = evaluate(func, {x : xValue});
    return fx[i];
	};

  const formula = diffFormutla[derivativeOrder][direction][accuracy];

  result.trueDerivativeFuncDueToOrder = func;

  const order = Object.keys(diffFormutla).indexOf(derivativeOrder);
  console.log( order );

  for ( let i = 0; i <= order; i++ ) {
    result.trueDerivativeFuncDueToOrder = derivative(result.trueDerivativeFuncDueToOrder, 'x').toString();
  }

  result.trueDerivativeResult = evaluate(result.trueDerivativeFuncDueToOrder, { x });

  let hValue = evaluate(formula.fraction, {h});
  for ( let key in formula ) {
    if ( key === "fraction" ) continue;

    const coefficient = formula[key];
    const termValue = coefficient * calculateFx(key);
    result.func[key] = termValue;
    result.estimateResult += termValue / hValue;
  }

  result.errorPercent = Math.abs(result.trueDerivativeResult - result.estimateResult) / result.trueDerivativeResult * 100;

  return result;
}

console.log("1.1");
console.log(differentiation("e^x", 2, 0.25, "forward_finite-divided-difference", "h", "first-derivative"));
console.log("\n1.2");
console.log(differentiation("e^x", 2, 0.25, "backward_finite-divided-difference", "h", "first-derivative"));
console.log("\n1.3");
console.log(differentiation("e^x", 2, 0.25, "centered_finite-divided-difference", "h^2", "first-derivative"));

console.log("\n\n2.1");
console.log(differentiation("e^(x/3)+x^2", -2.5, 0.1, "forward_finite-divided-difference", "h^2", "second-derivative"));
console.log("\n2.2");
console.log(differentiation("e^(x/3)+x^2", -2.5, 0.1, "backward_finite-divided-difference", "h^2", "second-derivative"));
console.log("\n2.3");
console.log(differentiation("e^(x/3)+x^2", -2.5, 0.1, "centered_finite-divided-difference", "h^4", "second-derivative"));


function f(x)  {
  return evaluate("e^(x/3)+x^2", {x});
}
