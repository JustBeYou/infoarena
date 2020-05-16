# --------------- Challenge 1 -------------------------
def count_change(money,coins):
  dp = [0 for i in range(money + 1)]
  dp[0] = 1
  
  for coin in coins:
    for currentMoney in range(coin, money + 1):
      dp[currentMoney] += dp[currentMoney - coin]
    
  return dp[money]
  

# --------------- Challenge 2 -------------------------
from itertools import product

signalsMap = {
  '.-' : 'A',
  '-..': 'D',
  '.'  : 'E',
  '--.': 'G',
  '..' : 'I',
  '-.-': 'K',
  '--' : 'M',
  '-.' : 'N',
  '---': 'O',
  '.-.': 'R',
  '...': 'S',
  '-'  : 'T',
  '..-': 'U',
  '.--': 'W'
}

morseCharList = [char for char in 'ETIANMSURWDKGO']
morseCharPrecedence = {char:index for index, char in enumerate(morseCharList)}

def possibilities(word):
  possibleDecodings = set()
  unknownSpots = word.count('?')

  if word in signalsMap:
    possibleDecodings.add(signalsMap[word])
  
  preparedWord = word.replace('?', '{}')
  for fillingSignals in product(['.', '-'], repeat = unknownSpots):
    knownSignal = preparedWord.format(*fillingSignals)
    if knownSignal in signalsMap:
      possibleDecodings.add(signalsMap[knownSignal])
      
  possibleDecodings = list(possibleDecodings)
  possibleDecodings.sort(key = lambda char: morseCharPrecedence[char])
  return possibleDecodings



# --------------- Challenge 3 -------------------------
# Python provides a parsing mechanism using the AST library, but I think the idea
# is to implement the parsing myself

from re import split

def calc(expression):
    expression = expression.replace(' ', '') 
    expression = [token for token in split(tokenizerExpression, expression) if token != '']
  
    polishNotation = toPolish(expression)
    return evaluate(polishNotation)

def evaluate(queue):
    results = []
    while len(queue) != 0:
        token = queue.pop(0)
        if isUnaryOperator(token):
            number = results.pop(-1)
            results.append(
                operatorEvaluation[token](number)
            )
        elif isOperator(token):
            y = results.pop(-1)
            x = results.pop(-1)
            results.append(
                operatorEvaluation[token](x, y)
            )
        else:
            results.append(token)
    return results[0]
        

def toPolish(expression):
    outputQueue = []
    operatorStack = []

    maybeUnary = True
    i = 0
    while i < len(expression):
        token = expression[i]
        
        if isNumber(token):
            number = 0
            if   isInteger(token): number = int(token)
            elif isFloat(token)  : number = float(token)
            outputQueue.append(number)
            maybeUnary = False

        elif isOperator(token):
            while len(operatorStack) != 0 and \
                  isOperator(operatorStack[-1]) and \
                  (
                      (mustBeUnary(token, maybeUnary) and precedence[operatorStack[-1]] > precedence[unaryVariant(token)])
                      or
                      (not mustBeUnary(token, maybeUnary) and precedence[operatorStack[-1]] >= precedence[token])
                  ):
                outputQueue.append(operatorStack.pop(-1))
            if mustBeUnary(token, maybeUnary):
                operatorStack.append(unaryVariant(token))
            else:
                operatorStack.append(token)
            maybeUnary = True
        elif token == '(':
            operatorStack.append(token)
            maybeUnary = True
        elif token == ')':
            while operatorStack[-1] != '(':
                outputQueue.append(operatorStack.pop(-1))
            operatorStack.pop(-1)
            maybeUnary = False

        i += 1
    while len(operatorStack) != 0:
        outputQueue.append(operatorStack.pop(-1))

    return outputQueue

def isNumber(token):
    return isInteger(token) or isFloat(token)

def isInteger(token):
    return token.isnumeric()

def isFloat(token):
    try:
        float(token)
        return True
    except:
        pass
    return False

def isOperator(token):
    return token in allOperators


def isUnaryOperator(token):
    return token in unaryOperators

def unaryVariant(token):
    return 'u' + token

def mustBeUnary(token, maybeUnary):
    return token in '+-' and maybeUnary

operators = [operator for operator in '+-*/'] 
unaryOperators = ['u+', 'u-'] 
allOperators = operators + unaryOperators
precedence = {
    '+': 1, '-': 1,
    '*': 2, '/': 2,
    'u+': 3, 'u-': 3, # unary variant
}
operatorEvaluation = {
    'u-': lambda x: -x,
    'u+': lambda x:  x,
    '+' : lambda x, y: x + y,
    '-' : lambda x, y: x - y,
    '*' : lambda x, y: x * y,
    '/' : lambda x, y: x / y,
}
# ugly regex to split the input into tokens
tokenizerExpression = '(' + '|'.join(
            '\\' + separator for separator in operators + ['(', ')']
    ) + ')'

