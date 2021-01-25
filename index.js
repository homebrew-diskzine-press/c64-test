
const { cc65, ca65, ld65 } = require('@homebrew-diskzine-press/cc65-node');
const { execSync } = require('child_process');

(async () => {

  const target = 'c64';

  await cc65({
    optimizer: {enable: true},
    target,
    outputFile: 'test.s',
  }, 'test.c');

  await ca65({
    target,
    outputFile: 'test.o',
  }, 'test.s');

  await ld65({
    target,
    outputFile: 'test.prg',
  }, 'test.o', 'c64.lib');

  execSync('c1541 -format diskname,id d64 test.d64 -attach test.d64 -write test.prg test');

})();

