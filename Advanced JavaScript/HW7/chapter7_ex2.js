function* generator()
{
    yield 'apples';
    yield 'banannas';
    return 'plums';
}

let generatorObject1= generator();
generatorObject1.next('banannas')