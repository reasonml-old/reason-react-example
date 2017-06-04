/**
 * @file console.style is micro-library for intuitively styling browser console text with CSS.
 * @author Daniel Lamb <dlamb.open.source@gmail.com>
 */
(function(console) {
  /**
   * @namespace console
   */

  /**
   * @namespace consoleStyle
   */

  /* istanbul ignore if */
  if (!console || !console.log) {
    return;
  }

  var colors = 'Black Blue Cyan Gray Green Magenta Red White Yellow'.split(' ');
  var rxTags = /<(css|b|i)(?:=['"](.*?)['"])?>(.*?)<\/(?:css|b|i)>/ig;
  var rxRules = /([a-z\-]+)\s?:\s?([^;'"]+);?/ig;
  var rxTokens = /%[sdifoO]/g;
  var rxImgs = /<img=['"](.*?)['"]>/ig;
  var bg = 'background';
  var px = 'px';
  var style;
  var wrap;

  /**
   * Regex mojo to parse the text to log in the console.
   * @function parse
   * @memberOf consoleStyle
   * @param {string} text - the text with styles to parse
   * @returns {Array} args - an array of console.log arguments
   */
  var parse = function(text) {
    var args = [text];
    if (typeof text === 'string') {
      text = text.replace(rxImgs, function(matchI, $1I) {
        var width;
        var height;
        var halfHeight;
        var halfWidth;
        var styles = ['font-size:1px'];
        $1I.replace(rxRules, function(matchR, $1R, $2R) {
          switch ($1R) {
            case bg:
            case bg + '-image':
              styles.push($1R+ ':' + $2R, bg + '-repeat:no-repeat');
              break;
            case 'width':
              width = $2R;
              break;
            case 'height':
              height = $2R;
              styles.push('line-height:' + $2R);
              break;
          }
        });
        halfWidth = Math.ceil(parseInt(width) / 2);
        halfHeight = Math.ceil(parseInt(height) / 2);
        styles.push(bg + '-size:' + width + ' ' + height);
        styles.push('padding:' + halfHeight + px + ' ' + halfWidth + px);
        return wrap('', styles.join(';'));
      });
      args[0] = text.replace(rxTags, function(matchT, $1T, $2T, $3T) {
        $2T = $2T || '';
        $3T = $3T.replace(rxTokens, '');
        switch ($1T) {
          case 'b':
            $2T += ';font-weight:bold';
            break;
          case 'i':
            $2T += ';font-style:italic';
            break;
        }
        args.push($2T, '');
        return '%c' + $3T + '%c';
      });
    }
    return args;
  };

  /**
   * Define color shortcut methods on the console.
   * @function colors
   * @memberOf console
   * @param {string} color - the CSS color rule to apply
   * @example console.style('Wow, this is ' + console.colors.green('so much') + ' better!');
   */
  console.colors = {};
  colors.forEach(function(color) {
    console.colors[color.toLowerCase()] = function(text) {
      return wrap(text, 'color:' + color);
    };
    console.colors['bg' + color] = function(text) {
      return wrap(text, bg + '-color:' + color);
    };
  });

  /**
   * Intuitively Style Browser Console Text with CSS.
   * @function style
   * @memberOf console
   * @param text - the text to style
   * @example console.style('Wow, this is <css="color:green;font-weight:bold;">so much</css> better!');
   */
  console.style = style = function() {
    var args = [].slice.call(arguments);
    console.log.apply(console, parse(args.shift()).concat(args));
  };

  /**
   * Wraps the given text in a <css> tag with the provided style rules.
   * @function wrap
   * @memberOf console
   * @param {string} text - the text to wrap
   * @param {string} rule - CSS rules to apply
   * @returns {string} - the wrapped text
   * @example console.style('I just ' + console.style.wrap('love', 'color:#c00;font-weight:bold;') + ' console.style');
   */
  console.style.wrap = wrap = function(text, rules) {
    return '<css="' + rules + '">' + text + '</css>';
  };

}(window.console));
