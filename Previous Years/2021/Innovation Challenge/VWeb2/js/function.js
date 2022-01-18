$(document).ready(() => {
    //Initialize Slick 
    $('#slider-main-home-page .slick-track').slick({
        autoplay: true,
        autoplaySpeed: 7500,
        dots: false,
        arrows: false,
        fade: true,
        speed: 1600,
        infinite: true,
        cssEase: 'ease-in-out',
    });
    $(".page-variable-container .slider .slide").slick({
      centerMode: true,
      centerPadding: '30px',
      slidesToShow: 5,
    });
    //Shadow border around Nav Bar after Height
    /*
    var $nav = $(".container").find(".navBar")
    $(document).scroll(function(){
      var scroll = $(document).scrollTop();
      if (scroll >= 0.6 * document.body.scrollHeight ){
        $nav.addClass("navShadow");
      } else {
        $nav.removeClass("navShadow");
      }
    });
    */
   var $nav = $("#container").find(".navBar");
   
   $(document).scroll(function(){
    var scroll = $(document).scrollTop();
     if (scroll >= 654){
       $nav.addClass("navShadow");
       $li.css("color", "black");
     } else {
       $nav.removeClass("navShadow");
       $li.css("color", "white");
     }
   });

    //SubMenu Code
    var $li = $("#menu").find(".li-nav");
    var $overlay = $("#container").find(".overlay");
    var $html = $("html");
    $li.each( function ( i ){
        $(this).attr( 'data-index', i);
    });

    
    $("#menu").find(".li-nav").on("mouseenter", function(){
      var j = parseInt( $(this).attr('data-index') );
      $li.each( function( i ){
        if ( i !== j ){
          $(this).addClass( 'dimmed' );
        }
        else{
         $(this).removeClass( 'dimmed' );
        }
      });
      var scroll = $(document).scrollTop();
        if (scroll >= 654) {
          $html.addClass('over-submenuWhite');
          $overlay.addClass('over-submenuWhite');
        } else {
         // $html.removeClass('over-submenuWhite');
          //$overlay.removeClass('over-submenuWhite');
          $html.addClass('over-submenu');
          $overlay.addClass('over-submenu');
        }
    });

    $("#menu").on("mouseleave", function(){
        $html.removeClass('over-submenu');
        $overlay.removeClass('over-submenu');
        $overlay.removeClass('over-submenuWhite');
        $li.removeClass('dimmed');
    });

    var $s = $("#panel")
    var $x = $(".top")
    $(".menuBar").on("mouseenter", function(){
      $s.css("opacity", 1);
      $x.addClass("hide");
    });

    $(".menuBar").on("mouseleave", function(){
      $s.removeAttr("style");
      $x.removeClass("hide");
    });
});





