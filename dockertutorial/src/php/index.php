<html>
 <head>
  <title>PHP Test</title>
 </head>
 <body>
<?php 
namespace proto\php;
error_reporting(E_ALL);

require_once '/usr/lib/php/ClassLoader/ThriftClassLoader.php';

use Thrift\ClassLoader\ThriftClassLoader;

$GEN_DIR = __DIR__ . "/gen-php/";

$loader = new ThriftClassLoader();
$loader->registerNamespace('Thrift', '/usr/lib/php');
$loader->registerDefinition('proto', $GEN_DIR);
$loader->register();

use \Thrift\Protocol\TBinaryProtocol;
use \Thrift\Transport\TSocket;
use \Thrift\Transport\TBufferedTransport;
use \Thrift\Exception\TException;

echo 'Hello World'; 

try {
  $socket = new TSocket('localhost', 9090);
  $transport = new TBufferedTransport($socket, 1024, 1024);
  $protocol = new TBinaryProtocol($transport);
  $client = new \proto\TimeClient($protocol);
  $nowtime = $client->getInfo();
  print "Current time from back-end: $nowtime\n";
} catch (TException $tx) {
  print 'TException: '.$tx->getMessage()."\n";
}

?> 
 </body>
</html>