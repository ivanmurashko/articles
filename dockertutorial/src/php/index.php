<?php 
error_reporting(E_ALL);

$GEN_DIR = __DIR__ . "/gen-php/";

require_once '/usr/lib/php/Thrift/ClassLoader/ThriftClassLoader.php';
use Thrift\ClassLoader\ThriftClassLoader;

$loader = new ThriftClassLoader();
$loader->registerNamespace('Thrift', '/usr/lib/php');
$loader->registerNamespace('proto', $GEN_DIR);
$loader->registerDefinition('proto', $GEN_DIR);
$loader->register();

use \Thrift\Protocol\TBinaryProtocol;
use \Thrift\Transport\TSocket;
use \Thrift\Transport\TBufferedTransport;
use \Thrift\Exception\TException;

try {
  $socket = new TSocket('172.17.0.1', 9191);
  $transport = new TBufferedTransport($socket, 1024, 1024);
  $transport->open();
  $protocol = new TBinaryProtocol($transport);
  $client = new \proto\TimeClient($protocol);
  $nowtime = $client->getInfo();
  print "Current time from back-end: $nowtime\n";
} catch (TException $tx) {
  print 'TException: '.$tx->getMessage()."\n";
}
?>