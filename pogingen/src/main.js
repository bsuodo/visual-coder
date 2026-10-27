let nodes_editor = {
    button: document.getElementById("nodes_editor_button"),
    widget: document.getElementById("nodes_editor_widget"),
    toggle: false
};

nodes_editor.button.addEventListener("click", () => {
    nodes_editor.toggle = !nodes_editor.toggle;

    nodes_editor.button.style.left = parseInt(getComputedStyle(nodes_editor.button).left, 10) + (nodes_editor.toggle ? -512 : 512) + "px";
    nodes_editor.widget.style.left = parseInt(getComputedStyle(nodes_editor.widget).left, 10) + (nodes_editor.toggle ? -512 : 512) + "px";
});

let mouse_track = {
    x: 0,
    y: 0,
    origin_x: 0,
    origin_y: 0,
    workspace: false
};

window.onmousemove = (info) => {
    mouse_track = {
        ...mouse_track,
        x: info.clientX,
        y: info.clientY
    }
};

let workspace = document.getElementById("workspace");

workspace.addEventListener("mousedown", (info) => {
    mouse_track.origin_x = info.clientX;
    mouse_track.workspace = true;
});

workspace.onmouseup = (info) => {
    mouse_track.workspace = false;
}

function Loop()
{
    let nieuw_pos_x = parseInt(getComputedStyle(workspace).backgroundPositionX, 10);

    nieuw_pos_x += (mouse_track.origin_x - mouse_track.x) / 6;
    mouse_track.origin_x -= (mouse_track.origin_x - mouse_track.x) / 6;

    if (workspace)
        workspace.style.backgroundPositionX = nieuw_pos_x + "px";

    requestAnimationFrame(Loop);
}

requestAnimationFrame(Loop)