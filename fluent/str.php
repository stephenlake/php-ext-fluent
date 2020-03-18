<?php
namespace Fluent;

class Str
{
    private str;
    private ignoreCase;

    public function __construct($s = "")
    {
        let this->str = $s;
        let this->ignoreCase = false;
    }

    public function startsWith($needle)
    {
        var $str = this->str;
        var $ndl = $needle;
        var $length = strlen($ndl);

        if (this->ignoreCase) {
          return (substr($str, 0, $length) === $ndl);
        }

        return (substr($str, 0, $length) === $ndl);
    }

    public function endsWith($needle)
    {
        var $str = this->str;
        var $ndl = $needle;

        if (this->ignoreCase) {
            var $str = strtolower($str);
            var $ndl = strtolower($needle);
        }

        echo $str .":". $ndl;

        var $length = strlen($ndl);

        if ($length == 0) {
            return true;
        }

        return (substr($str, -$length) === $ndl);
    }

    public function ignoreCase() {
       let this->ignoreCase = true;

       return this;
    }

    public function ignoringCase() {
      return $this->ignoreCase;
    }

    public static function create($str) {
        return new Str($str);
    }

    public static function from($str) {
        return self::create($str);
    }

    public static function of($str) {
        return self::create($str);
    }

    public function __toString() {
        return this->str;
    }
}
